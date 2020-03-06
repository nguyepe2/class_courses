#include "demon.h"
#include "world.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


/* Function: demon
 * Descripiton: Default constructor for demon class
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
demon::demon() {

}

/*
void demon::set_num_demons() {
  cout << "How many demons do you want?: ";
  cin >> num_demons;
}

int demon::get_num_demons() {
  return num_demons;
} 

void demon::set_name_d() { 
  std::string *name;
  name = new std::string[num_demons];
  for(int i=0; i<num_demons; i++) {
    cout << "what would you like to name this demon?: ";
    cin >> name_d;
    name[i]=name_d;
    
  }
}

string demon::get_name_d() {
  return name_d;
} 
*/


/* Function: getDamage
 * Descripiton: Returns the damage dealt by demons
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int demon::getDamage() {
  int damage;
  if((type==2) || (type==1))
     if(rand() % 100 < 5) {
	damage=damage+50;
	cout << "Demonic attack inflicts 50 "
	  << " additional damage points!" << endl;

     }
}
/*
void balrog::set_num_balrogs() {
  cout << "How many balrogs do you want?: ";
  cin >> num_balrogs;
}

int balrog::get_num_balrogs() {
  return num_balrogs;
} 

void balrog::set_name_b() { 
  std::string *name;
  name = new std::string[num_balrogs];
  for(int i=0; i<num_balrogs; i++) {
    cout << "what would you like to name this balrog?: ";
    cin >> name_b;
    name[i]=name_b;
    
  }
}

string balrog::get_name_b() {
  return name_b;
} */
