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



int main(int argc, char *argv[]) {
  srand(time(NULL));
  int i;
  char characters[27]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

  if(argc==2 && atoi(argv[1])) {
    for(i=0; i<atoi(argv[1]); i++) {
      int r=rand() % 27;
      printf("%c", characters[r]);
    }
    printf("\n"); //creates newline to make output readable and to signify end of file
  }

  /*write to stderr instead of stdout
    can be checked by doing "keygen  | grep ." in terminal, note the two spaces after keygen
    (output should be in white)
    if output is red, then it's being output to stdout
    */
  else {
    fprintf(stderr, "%s", "invalid input\n");
  }

  return 0;
}
