#include "gnome.h"
//#include "world.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/* Function: gnome
 * Descripiton: Default constructor for the gnome class
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
gnome::gnome() {

}


int gnome::getDamage() {
  int damage;
  if(type==4) {
    if((rand() % 15)==0) {
      cout << "Attack inflicts " << damage + 10
        << " additional damage points!" << endl;
      damage = damage + 10;
    }
  }
}

