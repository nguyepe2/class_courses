#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "psychic.h"


/* Function: get_capture_rate
 * Description: determines whether or not the psychic pokemon was caught
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
void psychic::get_capture_rate() {
  srand (time(NULL));
  int rng = rand() % 100 + 1;
  std::cout << rng << ' ';
  if(rng < 26)
     std::cout << "You caught a psychic pokemon!" << std::endl;
  else
     std::cout << "The psychic pokemon ran away!" << std::endl;
}
