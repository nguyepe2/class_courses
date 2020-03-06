#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>

int main() {
     pid_t spawnpid = fork();
     switch (spawnpid)
     {
        case -1: exit(1); break;
        case 0: exit(0); break;
        default:  break;
     }
     printf("XYZZY\n");


}
