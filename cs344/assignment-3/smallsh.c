#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include<fcntl.h>

int pidArray[1000];
int i=0;
int background=0; //0 is foreground, 1 is background
int originalPid;
struct sigaction SIGINT_action={0}, ignore_action={0}, SIGTSTP_action = {0}, TERM_action = {0};
int allowBackground=1;


char *prompt(char str1[]) {
  printf(": ");
  fflush(stdout);
  fgets(str1, 2048, stdin);
  strtok(str1, "\n");
  //return str1;
}

void cd_prebuilt(int check, char* cmd[], int num) {

  int checkSuccess;

  if(num==1) {
    chdir(getenv("HOME"));
  }

  else {
    checkSuccess=chdir(cmd[1]);
    if(checkSuccess!=0) {   //if no directory with the name specified exists, print error message
      perror("Error");
      check=1;

    }
  }
}

void exit_prebuilt() {
  int count=0;
  int pid;

  for(count=0; count<1000; count++) {

    pid=pidArray[count];
    //printf("pid val: %d\n", pid);

    if(pid==0) { //if parent, exit to set exit status to 0
      _exit(0);
    }

    kill(pid, SIGKILL);
  }

  //_exit(0);
}


void status_prebuilt(pid_t child, int stat) {
    int end;
    int end2;
    int errNum=0;
    int sigNum=0;
    int success;

    getpid();
    //waitpid(child, &stat, 0);
    end=WIFEXITED(stat); //check to see if the child ended without a signal
    end2=WIFSIGNALED(stat); //check to see if child ended because of signal

    if(end) {
      errNum=WEXITSTATUS(stat); //grab the exit value of the child
    }

    if(end2) {
      sigNum=WTERMSIG(stat); //grab the value of the signal that killed the child
      printf("sig number: %d\n", sigNum);
      fflush(stdout);
    }

    if(errNum==0 && sigNum==0) { //if errNum and sigNum are unchanged, then operation successful
      success=0;
    }
    else {
      success=1;
    }

    printf("exit value %d\n", success);
    fflush(stdout);
}

//parses user input into an array
int args(char* str1, char* cmd[]) {
  char* arguments;
  int count=0;
  int j, k;
  arguments=strtok(str1, " ");

  while(arguments!=NULL) {
    cmd[count]=arguments;
    arguments=strtok(NULL, " ");

    count++;
  }

  for(j=0; j<count; j++) {
    for(k=0; k<strlen(cmd[j]); k++) {
      if(cmd[j][k]=='$' && cmd[j][k+1]=='$') {
        cmd[j][k]='\0';
        cmd[j][k+1]='\0';
        char temp[2048];

        sprintf(temp, "%s%d", cmd[j], originalPid); //expand "$$" to the process id
        strcpy(cmd[j], temp);

      }
    }
  }

  return count;
}


void catchSIGINT(int signo) {
  char* message = " terminated by signal 2\n";
  write(STDOUT_FILENO, message, 25);
}

void catchSIGTSTP(int signo) {
  if(allowBackground==1) { //1 if background is allowed, 0 if no background allowed
  char* message="\nEntering foreground-only mode (& is now ignored)\n";
  write(STDOUT_FILENO, message, 52);
  allowBackground=0;
}
  else {
    char* message=" \nExiting foreground-only mode\n";
    write(STDOUT_FILENO, message, 32);
  }

}


int main() {

  int k;
  pid_t parentPid;
  pid_t child;
  int stat;
  char temp1[2048];
  char* cmd[512];
  char* cd = "cd";
  char* quit = "exit";
  char* status = "status";
  char comment = '#';
  int changeDir;
  int stopping;
  int ignore;
  int state;
  int success;
  originalPid=getpid();

  ignore_action.sa_handler = SIG_IGN;
  ignore_action.sa_flags = SA_RESTART;
  sigfillset(&ignore_action.sa_mask);

  sigaction(SIGINT, &ignore_action, NULL);

  SIGINT_action.sa_handler = catchSIGTSTP; //called SIGINT_action, but actually is for SIGTSTP
  SIGINT_action.sa_flags = SA_RESTART;
  sigfillset(&SIGINT_action.sa_mask);


  sigaction(SIGTSTP, &SIGINT_action, NULL);

  TERM_action.sa_handler = catchSIGINT; //calls function to print out SIGINT signal number
  TERM_action.sa_flags = SA_RESTART;
  sigfillset(&TERM_action.sa_mask);


  sigaction(SIGINT, &TERM_action, NULL);

while(1) {
  char str1[2048];
  int fileThing=-1;
  int readFrom=0, readTo=0;
  prompt(str1);
  int num;
  num=args(str1, cmd);
  cmd[num]=NULL;
  background=0;
  ignore=1; //initializes and resets ignore "flag"
  int check=0;

  char first=str1[0];


  changeDir=strcmp(cmd[0], cd);
  stopping=strcmp(cmd[0], quit);
  state=strcmp(cmd[0], status);
  if(first==comment || first=='\n') { //if first char is '#' or not there, set ignore "flag"
    ignore=0;
  }

  if(changeDir==0) {
    cd_prebuilt(check, cmd, num);
  }

  else if(stopping==0) {
    exit_prebuilt();
}

  else if(ignore==0) {
    //do nothing if first char is #

  }

  else if(state==0) {
    status_prebuilt(child, stat);
  }

  else {

    if(allowBackground==0 && strcmp(cmd[num-1], "&")==0) { //if in foreground mode, ignore &
      cmd[num-1]=NULL;

    }

    else if(strcmp(cmd[num-1], "&")==0) {
      cmd[num-1]=NULL;
      background=1; //set background flag

    }

      child=fork();

      pidArray[i]=child; //store pid of child into global array
      i++;
      if(child==0) {

//got the redirection stuff from stackOverflow
      int fd0, fd1, il, innn=0, out=0;
      char input[2048], output[2048];

      for(il=0; cmd[il]!=NULL; il++) {
        if(strcmp(cmd[il], "<")==0) {

          cmd[il]=NULL;

          strcpy(input, cmd[il+1]);

          innn=2;
          readFrom=1;

        }
        else if(strcmp(cmd[il], ">")==0) {

          cmd[il]=NULL;
          strcpy(output, cmd[il+1]);
          out=2;
          readTo=1;

        }


      }

//if no redirection operator in user input, and command set to run in background, redirect to dev/null
        if(readFrom==0 && readTo==0 && background==1) {
          freopen("/dev/null", "w", stdout);
          freopen("/dev/null", "r", stdin);
          fcloseall();

      }

      if(innn) { //if < is inside of user input

        if((fd0=open(input, O_RDONLY, 0)) < 0) {
          perror("Couldn't open input file");
          _exit(1);
        }

        dup2(fd0, STDIN_FILENO);
        close(fd0);

      }

      if(out) { //if > is inside user input

        if((fd1=creat(output, 0644)) < 0) {
          perror("couldn't open output file");
          _exit(1);
        }
        dup2(fd1, STDOUT_FILENO);
        close(fd1);
      }

          if(background==0) { //if process not in background, it can be killed by SIGINT
            SIGINT_action.sa_handler=SIG_DFL;
            sigaction(SIGINT, &SIGINT_action, NULL);
            //status_prebuilt(child, stat);

          }
          else { //if process is in background, ignore SIGINT
            SIGINT_action.sa_handler=SIG_IGN;
            sigaction(SIGINT, &SIGINT_action, NULL);


          }
          execvp(cmd[0], cmd);

        // if execvp fails, tell the user what went wrong
        printf("%s: ", cmd[0]);
        fflush(stdout);
        perror("");
        _exit(1);
        //check=1;
      }

      else if(child > 0) { //in the parent



      if(background==1) {

        pid_t winter;
        winter=waitpid(child, &stat, WNOHANG); //check if a child's status has changed
        printf("background pid is: %d\n", child);
        fflush(stdout);

      }

      else {
        pid_t winter;
        winter=waitpid(child, &stat, 0);
      }

  }

else {
  perror("fork went wrong");
  _exit(1);
}

while(waitpid(-1, &stat, WNOHANG) > 0 ) {
  printf("child %d is terminated\n", child);
  status_prebuilt(child, stat);
  fflush(stdout);
}

} //ends else

} //ends while
  return 0;
}
