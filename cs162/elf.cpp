#include "elf.h"
#include "creature.h"
#include <cstdlib>
#include <iostream>
using namespace std;


/* Function: elf
 * Descripiton: Default constructor for the elf class
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
elf::elf() {

}

/*
void elf::set_num_elfs() {
  cout << "How many elfs do you want?: ";
  cin >> num_elfs;
}

int elf::get_num_elfs() {
  return num_elfs;
} */
/*
void elf::set_name_e() { 
  std::string *name;
  name = new std::string[num_elfs];
  for(int i=0; i<num_elfs; i++) {
    cout << "what would you like to name this elf?: ";
    cin >> name_e;
    name[i]=name_e;
    
  }
}

string elf::get_name_e() {
  return name_e;
} 
*/

/* Function: getDamage
 * Descripiton: Returns the damage dealt by elves
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int elf::getDamage() {
  int damage;
  if(type==3) {
    if((rand() % 10)==0) {
      cout << "Magical attack inflicts " << damage
        << " additional damage points!" << endl;
      damage = damage*2;
    }
  }
}

