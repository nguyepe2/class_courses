#include "balrog.h"
#include "world.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/* Function: balrog
 * Descripiton: Default constructor for the balrog class
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
balrog::balrog() {

}

/*
void balrog::set_num_balrogs() {
  cout << "How many balrogs do you want?: ";
  cin >> num_balrogs;
}

int balrog::get_num_balrogs() {
  return num_balrogs;
} */
/*
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
}
*/

/* Function: getDamage
 * Descripiton: Returns the damage dealt by balrogs
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int balrog::getDamage() {
  int damage;
  if(type==2) {
    int damage2 = (rand() % strength) +1;
    cout << " Balrog speed attack inflicts " << damage2
       << " additional damage points!" << endl;
    damage = damage+damage2;
  }
  return damage;
}
