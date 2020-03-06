/* Program Filename: pokemondriver.cpp
 * Author: Peter Nguyen
 * Date: 6/1/2017
 * Description: a game that tries to simulate pokemon go
 * Input: numbers
 * Output: a map, and your position
 */
#include <iostream>
#include <stdlib.h>
#include "location.h"
#include "pokemon.h"
#include "cave.h"
#include "pokestop.h"
#include "flying.h"
using namespace std;

int main(int argc, char **argv) {
  location l;
  pokemon p;
  cave c;
  pokestop s;
  flying f;
  //s.get_event();
  //c.get_event();
  l.make_map(argc, argv);
  //l.place_event(argv);
  //f.get_capture_rate();
  //s.get_event();
}
