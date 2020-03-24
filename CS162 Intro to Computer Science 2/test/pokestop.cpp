#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "pokestop.h"

/* Function: get_event
 * Description: passed from event class because pokestops are an event
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void pokestop::get_event() {
   std::cout << "You found a pokestop!" << std::endl;
}

/* Function: set_pokeballs
 * Description: determines how much pokeballs are received from a pokestop
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void pokestop::set_pokeballs() {
   int add_pokeballs;
   pokeballs=10;
   srand (time(NULL));
   //std::cout << "You found a pokestop!" << std::endl;
   add_pokeballs=(rand() % 7) + 3;
   std::cout << "You received: " << add_pokeballs << " pokeballs" << std::endl;
  pokeballs=pokeballs + add_pokeballs;
}

/* Function: get_pokeballs
 * Description: outputs the amount of pokeballs the user has
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
int pokestop::get_pokeballs() {
  return pokeballs;
}
