#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "pokemon.h"
#include "flying.h"
 
/* Function: get_capture_rate
 * Description: determines whether or not the flying pokemon was caught
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void flying::get_capture_rate() {
  srand (time(NULL));
  int rng = rand() % 100 + 1;
  std::cout << rng << ' ';
  if(rng < 51)
     std::cout << "You caught a flying pokemon!" << std::endl;
  else
     std::cout << "The flying pokemon ran away!" << std::endl;
}
