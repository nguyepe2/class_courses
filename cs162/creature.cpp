#include "creature.h"
#include <iostream>
#include <stdlib.h>

/* Function: creature()
 * Descripiton: Default constructor for creature class
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
creature::creature() {

}


/* Function: getDamage
 * Descripiton: Returns the damage dealt by the creatures
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int creature::getDamage() {
  int damage;
  damage=rand() % strength;
  return damage;
}


/* Function: getSpecies
 * Descripiton: Returns the type of creature
 * Parameters: an integer that specifies the type
 * Preconditions: none
 * Postconditions: none
 */
string creature::getSpecies(int type) {
  switch(type) {
    case 0: return "Human";
    case 1: return "Cyberdemon";
    case 2: return "Balrog";
    case 3: return "Elf";
    case 4: return "Gnome";
  }
  return "Unknown";
}


void creature::setHitpoints(int h) {
 hitpoints=h;
}

void creature::getStrength() {
  return strength;
}

int creature::getHitpoints() {
  return hitpoints; 
}

creature::getDriver() {
  return *driver;
}

/*int creature::getDamage() {
  if((type==2) || (type==1))
     if((rand() % 100 < 5) {
	damage=damage+50;
	cout << "Demonic attack inflicts 50 "
	  << " additional damage points!" << endl;

     }
} */

/*int creature::getDamage() {
  int damage;
  if(type==3) {
    if((rand() % 10)==0) {
      cout << "Magical attack inflicts " << damage
        << " additional damage points!" << endl;
      damage = damage*2;
    }
  }
} */

/*int creature::getDamage() {
  if(type==2) {
    int damage2 = (rand() % strength) +1;
    cout << " Balrog speed attack inflicts " << damage2
       << " additional damage points!" << endl;
    damage = damage+damage2;
  }
  return damage;
} */
