// Simple command-line kernel monitor useful for
// controlling the kernel and exploring the system interactively.

#include <inc/stdio.h>
#include <inc/string.h>
#include <inc/memlayout.h>
#include <inc/assert.h>
#include <inc/x86.h>

#include <kern/console.h>
#include <kern/monitor.h>
#include <kern/kdebug.h>
#include <kern/trap.h>

#define CMDBUF_SIZE	80	// enough for one VGA text line


struct Command {
	const char *name;
	const char *desc;
	// return -1 to force monitor to exit
	int (*func)(int argc, char** argv, struct Trapframe* tf);
};

// LAB 1: add your command to here...
static struct Command commands[] = {
	{ "help", "Display this list of commands", mon_help },
	{ "kerninfo", "Display information about the kernel", mon_kerninfo },
    { "backtrace", "backtrace stuff", mon_backtrace }
};

/***** Implementations of basic kernel monitor commands *****/

int
mon_help(int argc, char **argv, struct Trapframe *tf)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(commands); i++)
		cprintf("%s - %s\n", commands[i].name, commands[i].desc);
	return 0;
}

int
mon_kerninfo(int argc, char **argv, struct Trapframe *tf)
{
	extern char _start[], entry[], etext[], edata[], end[];

	cprintf("Special kernel symbols:\n");
	cprintf("  _start                  %08x (phys)\n", _start);
	cprintf("  entry  %08x (virt)  %08x (phys)\n", entry, entry - KERNBASE);
	cprintf("  etext  %08x (virt)  %08x (phys)\n", etext, etext - KERNBASE);
	cprintf("  edata  %08x (virt)  %08x (phys)\n", edata, edata - KERNBASE);
	cprintf("  end    %08x (virt)  %08x (phys)\n", end, end - KERNBASE);
	cprintf("Kernel executable memory footprint: %dKB\n",
		ROUNDUP(end - entry, 1024) / 1024);
	return 0;
}

int
mon_backtrace(int argc, char **argv, struct Trapframe *tf)
{
	// LAB 1: Your code here.
    // HINT 1: use read_ebp().
    // HINT 2: print the current ebp on the first line (not current_ebp[0])
    //
    //when your read_ebp()[0] == 0, you may stop
    int *ebp = (int *)read_ebp();
    int i, j;
    struct Eipdebuginfo info;

    debuginfo_eip(ebp[1], &info);
    int eip_addr = (info.eip_fn_addr - ebp[1]) * -1;
	//int fn_name_len = info.eip_fn_namelen;		// Length of function name

    cprintf("ebp %x eip %x args", ebp, ebp[1]);
    for (i=2; i<7; i++) {
        cprintf(" %08x ", ebp[i]);
   //    ebp = ebp + 8;
    }
       //ebp = ebp + 8;
    cprintf("%s", "\n");

    cprintf("%s:%d: %.*s+%d %s ", info.eip_file, info.eip_line, info.eip_fn_namelen, info.eip_fn_name, eip_addr, "\n");
    while (ebp[0] !=0) {
        ebp = ebp + 8;
        debuginfo_eip(ebp[1], &info);
        cprintf("ebp %x eip %x args", ebp, ebp[1]);
        for (j=2; j<7; j++) {
            cprintf(" %08x ", ebp[j]);

        }
        cprintf("%s", "\n");
	    //uintptr_t eip_fn_addr;		// Address of start of function
        //int fn_adder = abs(info.eip_fn_addr-ebp[1]);
        eip_addr = (info.eip_fn_addr - ebp[1]) * -1;
    cprintf("%s:%d: %.*s+%d %s ", info.eip_file, info.eip_line, info.eip_fn_namelen, info.eip_fn_name, eip_addr, "\n");
    }

    //ebp = (int *)read_ebp();
    //debuginfo_eip(ebp[1], info);

//debuginfo_eip(uintptr_t addr, struct Eipdebuginfo *info)
    return 0;
}



/***** Kernel monitor command interpreter *****/

#define WHITESPACE "\t\r\n "
#define MAXARGS 16

static int
runcmd(char *buf, struct Trapframe *tf)
{
	int argc;
	char *argv[MAXARGS];
	int i;

	// Parse the command buffer into whitespace-separated arguments
	argc = 0;
	argv[argc] = 0;
	while (1) {
		// gobble whitespace
		while (*buf && strchr(WHITESPACE, *buf))
			*buf++ = 0;
		if (*buf == 0)
			break;

		// save and scan past next arg
		if (argc == MAXARGS-1) {
			cprintf("Too many arguments (max %d)\n", MAXARGS);
			return 0;
		}
		argv[argc++] = buf;
		while (*buf && !strchr(WHITESPACE, *buf))
			buf++;
	}
	argv[argc] = 0;

	// Lookup and invoke the command
	if (argc == 0)
		return 0;
	for (i = 0; i < ARRAY_SIZE(commands); i++) {
		if (strcmp(argv[0], commands[i].name) == 0)
			return commands[i].func(argc, argv, tf);
	}
	cprintf("Unknown command '%s'\n", argv[0]);
	return 0;
}

void
monitor(struct Trapframe *tf)
{
	char *buf;

	cprintf("Welcome to the JOS kernel monitor!\n");
	cprintf("Type 'help' for a list of commands.\n");

	if (tf != NULL)
		print_trapframe(tf);

	while (1) {
		buf = readline("K> ");
		if (buf != NULL)
			if (runcmd(buf, tf) < 0)
				break;
	}
}
