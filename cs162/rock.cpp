#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "rock.h"

/* Function: get_capture_rate
 * Description: determines whether or not the rock pokemon was caught
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void rock::get_capture_rate() {
   srand (time(NULL));
   int rng = rand() % 100 + 1;
   if(rng < 76) {
      std::cout << "You caught a rock pokemon!" << std::endl;
   }
   else
      std::cout << "The rock pokemon ran away!" << std::endl;
}

/* Function: catch_pokemon
 * Description: calls the get_capture_rate function
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void rock::catch_pokemon() {
      rock::get_capture_rate();
}
