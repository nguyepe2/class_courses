#include "world.h"
#include "creature.h"
#include "human.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
#include "elf.h"
#include <iostream>
#include <string>
using namespace std;

/* Function: world
 * Description: Default constructor for the world class
 * Parameters: None
 * Preconditions: none
 * Postconditions: none
 */
world::world() {

}

/* Function: ~world
 * Description: Deconstructor for the world class
 * Parameters: none
 * Preconditions: world class exists
 * Postconditions: dynamic memory is deleted
 */
world::~world() {
  // for(int i=0; i<num_humans; i++)
  // delete [] name;
}

/* Function set_money
 * Description: asks the user how much money they want to start off with
 * Parameters: none
 * Preconditions: none
 * Postconditions: user now has a certain amount of money
 */
void world::set_money() {
  cout << "how much money would you like to start off with? Note that each creature costs 100: ";
  cin >> money;
}

/* Function: get_money
 * Description: calculates how much money the user has after purchasing the desired amount of creatures
 * Parameters: none
 * Preconditions: the creatures exist
 * Postconditions: Money is displayed
 */
int world::get_money() {
   set_num_humans();
   set_num_balrogs();
   set_num_cyberdemons();
   set_num_elfs();
   set_num_gnomes();
   money = (money - (cost*num_humans + cost*num_balrogs + cost*num_cyberdemons + cost*num_elfs + cost*num_gnomes));
   cout << "you have: ";
   return money;
}

/* Function: cost
 * Description: sets the amount that each creature costs
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
const double world::cost=100;

/* Function: get_cost
 * Descripiton: displays how much each creature costs
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
const double world::get_cost() {
  return cost;
}


/* Function: set_num_humans
 * Descripiton: asks the user how many humans they want
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_num_humans() {
  cout << "How many humans do you want?: ";
  cin >> num_humans;
}


/* Function: get_num_humans
 * Descripiton: Returns how many humans the user wants
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int world::get_num_humans() {
  return num_humans;
} 


/* Function: set_name_h
 * Descripiton: allows the user to name each human they buy
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_name_h() { 
  //std::string *name;
   std::string* name = new std::string[num_humans];
  for(int i=0; i<num_humans; i++) {
    cout << "what would you like to name this human?: ";
    cin >> name_h;
    name[i]=name_h; 
 /* for(int i=0; i<num_humans; i++) {
    delete name[i].name_h;
  }
  delete [] name; */
  }
}


/* Function: get_name_h
 * Descripiton: Returns the names of the humans
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
string world::get_name_h() {
  return name_h;
} 


/* Function: set_num_balrogs
 * Descripiton: asks the user how many balrogs they want
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_num_balrogs() {
  cout << "How many balrogs do you want?: ";
  cin >> num_balrogs;
}


/* Function: get_num_balrogs
 * Descripiton: Returns how many balrogs the user wants
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int world::get_num_balrogs() {
  return num_balrogs;
} 


/* Function: set_name_b
 * Descripiton: allows the user to name each balrog they buy
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_name_b() { 
  std::string *name;
  name = new std::string[num_balrogs];
  for(int i=0; i<num_balrogs; i++) {
    cout << "what would you like to name this balrog?: ";
    cin >> name_b;
    name[i]=name_b;
    
  }
}


/* Function: get_name_b
 * Descripiton: Returns the names of the balrogs
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
string world::get_name_b() {
  return name_b;
}


/* Function: set_num_cyberdemons
 * Descripiton: asks the user how many cyberdemons they want
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_num_cyberdemons() {
  cout << "How many cyberdemons do you want?: ";
  cin >> num_cyberdemons;
}


/* Function: get_num_cyberdemons
 * Descripiton: Returns how many cyberdemons the user wants
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int world::get_num_cyberdemons() {
  return num_cyberdemons;
} 

void world::set_name_c() { 
  std::string *name;
  name = new std::string[num_cyberdemons];
  for(int i=0; i<num_cyberdemons; i++) {
    cout << "what would you like to name this cyberdemon?: ";
    cin >> name_c;
    name[i]=name_c;
    
  }
}


/* Function: get_name_c
 * Descripiton: Returns the names of the cyberdemons
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
string world::get_name_c() {
  return name_c;
} 


/* Function: set_num_elfs
 * Descripiton: asks the user how many elves they want
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_num_elfs() {
  cout << "How many elves do you want?: ";
  cin >> num_elfs;
}


/* Function: get_num_elfs
 * Descripiton: Returns how many elfs the user wants
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int world::get_num_elfs() {
  return num_elfs;
} 


/* Function: set_name_e
 * Descripiton: allows the user to name each elf they buy
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_name_e() { 
  std::string *name;
  name = new std::string[num_elfs];
  for(int i=0; i<num_elfs; i++) {
    cout << "what would you like to name this elf?: ";
    cin >> name_e;
    name[i]=name_e;
    
  }
}


/* Function: get_name_e
 * Descripiton: Returns the names of the elves
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
string world::get_name_e() {
  return name_e;
}


/* Function: set_num_gnomes
 * Descripiton: asks the user how many gnomes they want
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_num_gnomes() {
  cout << "How many gnomes do you want?: ";
  cin >> num_gnomes;
}


/* Function: get_num_gnomes
 * Descripiton: Returns how many gnomes the user wants
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int world::get_num_gnomes() {
  return num_gnomes;
} 


/* Function: set_name_g
 * Descripiton: allows the user to name each gnome they buy
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void world::set_name_g() { 
  std::string *name;
  name = new std::string[num_gnomes];
  for(int i=0; i<num_gnomes; i++) {
    cout << "what would you like to name this gnome?: ";
    cin >> name_g;
    name[i]=name_g;
    
  }
}


/* Function: get_name_g
 * Descripiton: Returns the names of the gnomes
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
string world::get_name_g() {
  return name_g;
}


/* Function: battle
 * Descripiton: Initiates the battle sequence
 * Parameters: none
 * Preconditions: You have creatures
 * Postconditions: you see which creatures are battling
 */
void world::battle() {
  creature c;
  int type;
  cout << "Welcome to battling! " << endl;
  cout << "Enter the type of creature that you want to see battle (0=human, 1=cyberdemon, 2=balrog, 3=elf, 4=gnome)";
  cin >> type;
  c.getSpecies(type);
}
