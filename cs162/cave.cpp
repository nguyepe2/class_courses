#include <iostream>
#include "cave.h"

/* Function: get_event
 * Description: get_event function passed from event class because encountering a cave is an event
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void cave::get_event() {
   std::cout << "You found a cave!" << std::endl;
}
