#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

char* rooms[7]; //global array that's supposed to hold connections


//code from 2.4 manipulating directories
void findNewestDir(DIR* dirToCheck, struct dirent *fileInDir) {
  int newestDirTime = -1; // Modified timestamp of newest subdir examined
  char targetDirPrefix[32] = "nguyepe2.rooms."; // Prefix we're looking for
  char newestDirName[256]; // Holds the name of the newest dir that contains prefix
  memset(newestDirName, '\0', sizeof(newestDirName));

  //DIR* dirToCheck; // Holds the directory we're starting in
  //struct dirent *fileInDir; // Holds the current subdir of the starting dir
  struct stat dirAttributes; // Holds information we've gained about subdir

  dirToCheck = opendir("."); // Open up the directory this program was run in

  if (dirToCheck > 0) // Make sure the current directory could be opened
  {
    while ((fileInDir = readdir(dirToCheck)) != NULL) // Check each entry in dir
    {
      if (strstr(fileInDir->d_name, targetDirPrefix) != NULL) // If entry has prefix
      {
        //printf("Found the prefex: %s\n", fileInDir->d_name);
        stat(fileInDir->d_name, &dirAttributes); // Get attributes of the entry

        if ((int)dirAttributes.st_mtime > newestDirTime) // If this time is bigger
        {
          newestDirTime = (int)dirAttributes.st_mtime;
          memset(newestDirName, '\0', sizeof(newestDirName));
          strcpy(newestDirName, fileInDir->d_name);
          //printf("Newer subdir: %s, new time: %d\n",
          //       fileInDir->d_name, newestDirTime);
        }
      }
    }
  }

  closedir(dirToCheck);
  chdir(newestDirName);


  //return newestDirName;
}

int getMaxLines(char* filesNames[], int maxLines[], int i) {
  //int i;
  //for(i=0; i<7; i++) {
    FILE* fileThing=fopen(filesNames[i], "r");
    int count=0;
    char store;
    for(store=getc(fileThing); store!=EOF; store=getc(fileThing)) {
      if(store=='\n') {
        count++;    //count represents the amount of lines in the file
      }
    }
    //maxLines[i]=count;    //store amount of lines for each file into maxLines array
    fclose(fileThing);
    return count;
  //}
}

char* changeRooms(char* token) {
  int compare=1;
  char str1[20];
  int k=0;
  int i;

  while(compare!=0) {
  //k++;
  printf("WHERE TO? >");
  scanf("%s", str1);
  //printf("choice: %s\n", str1);
  for(i=0; i<7; i++) {
    //printf("rooms: %s\n", rooms[i]);
    compare=strcmp(str1, rooms[i]);  //compares user input against room connections
    if(compare==0) {
      break;
    }
  }

    printf("ROOM NOT RECOGNIZED, PLEASE TRY AGAIN\n");
  }

  return str1;
}



void getConnections(char* filesNames[], int maxLines[], int i, int j, FILE* fileThing, char dest[], char* token, char a[], char n[]) {
  char lining[256];
  printf("CURRENT LOCATION: %s\n", filesNames[i]);
  printf("POSSIBLE CONNECTIONS: ");
  //memset(connects, '\0', sizeof(connects));
  char* val;
  int k=0;
  int num;
  //for(k=0; k<maxLines[i]; k++) {
    while(fgets(lining, sizeof(lining), fileThing)) {
      k++;
      if(k!=1 && k!=maxLines[i]) { //don't read from first and last lines
        strncpy(dest, lining, sizeof(lining));

        token=strtok(dest, a);
        for(j=0; j<2; j++) {
          token=strtok(NULL, a);
        }
        token=strtok(token, n);
        val=token;
        rooms[k]=val;   //set room connections to the rooms array
        //strcpy(rooms[k], val); //for some reason, this just crashes the program
        //printf("%s", rooms[k]);
        //changeRooms(token);

        if(k==maxLines[i]-1) {
          printf("%s.\n", val); //if last room, add a period
        }
        else {
          printf("%s, ", val); //if not last room connection, add a comma
        }


      }


      /*int h;
      for(h=0; h<maxLines[i]; h++) {
        strcpy(connects[h], val);
        printf("room: %s\n", connects[h]);
      } */

    }
    changeRooms(val);

}


int main()
{
  char* dirName;
  FILE *fp;
  char** filesNames;
  int maxLines[7];
  DIR* dirToCheck;
  struct dirent *fileInDir;
  filesNames=malloc(7*sizeof(char*));

  findNewestDir(dirToCheck, fileInDir);

  int i;
  for(i=0; i<7; i++) {
    filesNames[i]=malloc(10*sizeof(char));
  }

  i=0;
  dirToCheck=opendir(".");
  while((fileInDir=readdir(dirToCheck))!=NULL) {
    //printf("%s\n", fileInDir->d_name);
    if ( fileInDir->d_name[0] != '.' ){
      strcpy(filesNames[i], fileInDir->d_name); //copies file names (rooms) to filesNames Array
      i++;
    }
  }


for(i=0; i<7; i++) {
  maxLines[i]=getMaxLines(filesNames, maxLines, i); //fill maxLines array with numbers
  //printf("%d\n", maxLines[i]);
}

for(i=0; i<7; i++) {
  char dest[100];
  char line[256];
  const char a[2]=" ";
  const char n[2]="\n";
  //char** connects;
  //connects=malloc(7*sizeof(char*));

  char *token;
  int compare;
  int numConnect;
  char *starting="START_ROOM\n";
  char *ending="END_ROOM\n";
  FILE* fileThing=fopen(filesNames[i], "r");
  int number=0;

  /*for(i=0; i<7; i++) {
    connects[i]=malloc(10*sizeof(char));
  }*/

  while(fgets(line, sizeof(line), fileThing)) {
    number++;
    if(number==maxLines[i]) {
      //printf("%s\n", line);
      token=strtok(line, a);
      int j;
      for(j=0; j<2; j++) {
        token=strtok(NULL, a); //repeats to avoid the stuff you don't want
      }
    //printf("token: %s", token);
    compare=strcmp(starting, token);    //check to see if room_type is START_ROOM
    //printf("compare: %d\n", compare);
    fclose(fileThing); //close to reset the pointer thing
    FILE* fileThing=fopen(filesNames[i], "r");

    if(compare==0) {
      getConnections(filesNames, maxLines, i, j, fileThing, dest, token, a, n);
      //changeRooms();
    }


    }
  }

  fclose(fileThing);
}
  return 0;
}
