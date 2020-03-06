#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>


//First part of the Fisher-Yates shuffle Algorithm
void swap (int* a, int* b) {
  int temp=*a;
  *a=*b;
  *b=temp;

}

//Second part of the Fisher-Yates shuffle Algorithm
void randomize(char* arr[], int n) {
  int j;
  srand(time(NULL));
  for(j=9; j>0; j--) {    //starts at 9 because that's one less than the maximum size of the array
    int randNum;
    randNum=rand() % (j+1);
    swap(&arr[j], &arr[randNum]);

  }

}

int getRandomRoom(int arr[]) {
  int n;
  n=rand() % 7; //set to 7 so it grabs from array[0] to array[6]
  //printf("room name: %s\n", arr[n]);
  return n;
}

bool canAddConnectionFrom(int x, int arr[x][7]) {
  int connections=0;
  int i;
  //get value of room I'm checking (x), using value from getRandomRoom()

  for(i=0; i<7; i++) {    //increment values of 2nd part of array from 0 to 6, using i
    if(arr[x][i]==1) {    //check if values of [x][i]==1
      connections++;     //increment values using a counter (connections) if [x][i]==1
    }
  }
  if(connections < 6) {
    return true;        //if connections < 6, return true
  }
  else {
    return false;       //else, return false
  }
}

bool connectionAlreadyExists(int x, int y, int arr[x][7]) {
  if(arr[x][y]==1) { //if arr[x][y]==1, then there is a connection between rooms x and y
    return true;
  }
  else {
    return false;
  }
}

void connectRooms(int x, int y, int arr[x][7]) {
  arr[x][y]=1;
}

bool isSameRoom(int x, int y) {
  if(x==y) {
    return true;
  }
  else {
    return false;
  }
}

void addRandomConnection(int arr1[], int arr2[][7]) {
  int A;
  int B;
  while(true) {

    A=getRandomRoom(arr1); //arr1=chosenRoomNames

    if(canAddConnectionFrom(A, arr2)==true) {
      break;
    }
  }
  do {
    B=getRandomRoom(arr1);
  } while(canAddConnectionFrom(B, arr2)==false || isSameRoom(A,B)==true || connectionAlreadyExists(A,B, arr2)==true);

  connectRooms(A,B, arr2); //arr2=outboundConnections
  connectRooms(B,A, arr2);
}

bool isGraphFull(int arr[][7]) {
  int i;
  int j;
  int count=0;
  for(i=0; i<7; i++) {

    for(j=0; j<7; j++) {
      if(arr[i][j]==1) { //iterate through 2D array, and count connections between rooms
        count++;
      }
    }

    if(count < 3 || count > 6) { //if any room has less than 3 connections or more than 6
      return false;
    }
    //i++;
    count=0; //reset count
  }
  return true;
}

int main() {
  FILE *fp;
  FILE *fpoint;
  char rooms[]="nguyepe2.rooms.";
  char buffer[20];
  int process_id=getpid();
  char* availableNames[10]={"bedroom", "bathroom", "library", "office", "kitchen", "dining", "laundry", "attic", "basement", "garage"};
  int chosenRoomNames[7];
  int chosenRoomTypes[7];
  int outboundConnections[7][7];
  int i, j;
  int count=1;
  char* roomtype;

  sprintf(buffer, "%d", process_id);
  char* dirName=strcat(rooms, buffer); //combines room prefix and pid
  mkdir(rooms, 0755);

  chdir(dirName);
  randomize(availableNames, 9);

/* Create room types */
  int n;
  int starting=0;
  int ending=0;
  for(i=0; i<7; i++) {
  n=rand() % 3; //want max number generated to be 2
  if(n==0 && starting!=1) {
    starting=1;
  }
  else if(n==2 && ending!=1) {
    ending=1;
  }
  else {
    n=1;
  }

    chosenRoomTypes[i]=n;
    if(i==6 && starting==0) {
      chosenRoomTypes[1]=0; //forces starting room to exist
    }
    if(i==6 && ending==0) {
      chosenRoomTypes[6]=2; //forces ending room to exist
    }
  }

/* End of creating room types */

for(i=0; i<7; i++) {
  chosenRoomNames[i]=availableNames[i];
  fp = fopen(chosenRoomNames[i], "w+");
  fprintf(fp, "ROOM NAME: %s\n", chosenRoomNames[i]);

  fclose(fp);
/*End of assigning room types */

}

  while(isGraphFull(outboundConnections)==false) {
    addRandomConnection(chosenRoomNames, outboundConnections);
  }

// Prints out rooms that files are connected to
  for(i=0; i<7; i++) {
    fpoint = fopen(chosenRoomNames[i], "a");
    for(j=0; j<7; j++) {
      //printf("num: %d\n", outboundConnections[i][j]);
      if(outboundConnections[i][j]==1) {
        fprintf(fpoint, "CONNECTION %d: %s\n", count, chosenRoomNames[j]);
        count++;
      }
    }
    count=1; //reset count
    fclose(fpoint);
  }

  for(i=0; i<7; i++) {
    fpoint = fopen(chosenRoomNames[i], "a");
    /* Assign room types */
      if(chosenRoomTypes[i]==0) {
        roomtype = "START_ROOM";
      }
      if(chosenRoomTypes[i]==2) {
        roomtype = "END_ROOM";
      }
      if(chosenRoomTypes[i]==1) {
        roomtype = "MID_ROOM";
      }

      fprintf(fpoint, "ROOM TYPE: %s\n", roomtype);

      fclose(fpoint);
  }

  return 0;
}
