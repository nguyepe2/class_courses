/* Program Filename: assign5.cpp
 * Author: Peter Nguyen
 * Date: 3/5/2017
 * Description: A program that simulates bowling
 * Input: Number of players and their names
 * Output: The scoreboard, how much pins they knocked down, and the winner of the game
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
#define ROWS 3
#define COLS 10

/* Function: players
 * Description: Takes the number of players
 * Parameters: The number of players
 * Preconditions: the number of players is a positive integer
 * Postcondition: None
 * Return: the amount of players
 */
int players(int &num_players) {
   do{
   cout << "How many players are there?: ";
   cin >> num_players;
   }while(num_players<0);
}

/* Function: player_name
 * Description: Takes the names of the players
 * Parameters: Number of players and a list of names
 * Preconditions: That there are players
 * Postconditions: Copies the list of names
 * Return: a copy of the list of names
 */
void player_name(int &num_players, char name_list[][16]) {
char name[16];
//cin.ignore('\n');
//cin.clear();
cin.ignore();
for(int i=0; i<num_players; i++) {
  cout << "What is your name, player "<< i+1 <<"?: " ;
  cin.getline(name,16);
  strcpy(name_list[i], name);
}
}

/* Function: rng
 * Description: Generates a random number to simulate the knocking down of pins
 * Parameters: None
 * Preconditions: none
 * Postconditions: none
 * Return: the randomly generated number
 */
int rng() {
   int rand_num;
   srand(time(NULL));
   rand_num=rand()%11;
   cout << "You knocked down " << rand_num << " pins!" << endl;
   if(rand_num==0)
      cout << "Gutter ball!" << endl;
   else if(rand_num==10)
      cout << "Strike!" << endl;
}

/*int frame_info() {
   int** array;
   array=new int*[ROWS];
   for(int i=0; i<ROWS; i++)
      array[i]=new int[COLS];
}

*/

/* Function: init_array
 * Description: Enters the users' scores into the board
 * Parameters: Two dimensional array
 * Preconditions: None
 * Postcondition: Updates the board
 * Return: the updated board
 */
int init_array(int **array) {
for(int i=0; i<ROWS; i++)
   for(int j=0; j<COLS; j++)
      array[i][j]=0;
cout << array[0][0] << endl;
}

/* Function: board
 * Description: creates the all the stuff to hold the scores inside the scoreboard
 * Parameters: Two dimensional array
 * Preconditions: the array exists
 * Postconditions: None
 * Return: Values inside the scoreboard
 */
int board(int ***array) {
//int **array;
*array=new int*[ROWS];
for(int i=0; i<ROWS; i++)
 (*array)[i]=new int[COLS];
init_array(*array);
}

/* Function: Frames
 * Description: Creates the scoreboard
 * Parameters: number of players, and the list of names
 * Preconditions: there are players
 * Postconditions: None
 * Return: the scoreboard
 */
int frames(int num_players, char name_list[]) {
cout << "            The Scoreboard" << endl;
cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |" << endl;
for(int i=0; i<num_players; i++)
   cout << name_list[i] << endl;
  // cout << name_list << endl;
   //cout << *name_list << endl;
   //cout << &name_list[i];
}

/* Function: erase
 * Description: Deletes arrays
 * Parameters: the array
 * Precondition: the array exists
 * Postcondition: None
 * Return: None
 */
void erase(int **array) {
delete [] array;
array=NULL;
}

int main() {
   int **array;
   int num_players;
   char player_names;
   char name;
   //int rand_num;
   //player_name(&num_players);
   players(num_players);  
   char name_list[num_players][16];
   player_name(num_players, name_list);
   rng();
   board(&array);
   frames(num_players,name_list[num_players]);
   erase(array);
//   init_array(array);
  // cout << array[0][0] << endl;
//   frame_info();
   return 0;
}

