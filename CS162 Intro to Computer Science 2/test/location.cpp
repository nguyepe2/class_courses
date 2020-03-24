#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pokemon.h"
#include "rock.h"
#include "psychic.h"
#include "flying.h"
#include "cave.h"
#include "pokestop.h"
#include "location.h"

/* Function: location
 * Description: Constructor for location function
 * Parameters: none
 * Preconditions: none
 * Postconditions: none
 */
location::location() {

}

/* Function: make_map
 * Description: makes the map and places events onto the map
 * Parameters: argc (argument count) and argv (what the argument says)
 * Preconditions: none
 * Postconditions: the map is made
 */ 
void location::make_map(int argc, char (*argv[])) {
   if((argc == 2) && (atoi(argv[1])) >= 3) {
      pokestop s;
      cave c;
      rock r;
      int i=0, j=0;
      bool loop=true;
      int map[i][j], spot;
      map[i][j]=0;
      srand (time(NULL));
      int rng, pokestop_rng, cave_rng, rock_rng;

      do{
	 rng = rand() % (atoi(argv[1])*atoi(argv[1])+1); //determines where the player spawns
      }while(rng<1);

      do{
	 pokestop_rng = rand() % (atoi(argv[1])*atoi(argv[1])+1); //determines where pokestop spawns
      }while(pokestop_rng < 1 || pokestop_rng==rng);

      do{
	 cave_rng = rand() % (atoi(argv[1])*atoi(argv[1])+1); //determines where cave spawns
      }while(cave_rng < 1 || cave_rng==rng || cave_rng==pokestop_rng);

      do{
	 rock_rng = rand() % (atoi(argv[1])*atoi(argv[1])+1); //determines where rock pokemon spawns
      }while(rock_rng < 1 || rock_rng==rng || rock_rng==pokestop_rng || rock_rng==cave_rng);

      for(int i=0; i<(atoi(argv[1])*atoi(argv[1])); i++) {
	 map[i][j]++; //increments the board
	 if(map[i][j]==rng) {
	    std::cout << 's'; //the letter s denotes where the player started/spawned
	 }
	 if(map[i][j]==pokestop_rng) {
#ifdef DEBUG
	    std::cout << "pokestop"; //shows where the pokestop is
#endif
	 }
	 if(map[i][j]==cave_rng) {
#ifdef DEBUG
	    std::cout << "cave"; //shows where the cave is
#endif
	 }
	 if(map[i][j]==rock_rng) {
#ifdef DEBUG
	    std::cout << "Geodude"; //shows where geodude is
#endif
	 }
	 std::cout << map[i][j] << ' ';
	 if(map[i][j] % (atoi(argv[1])) == 0) //outputs the board in a grid format
	    std::cout << std::endl;
      }
      do{
	 std::cout << "Enter where you want to move: ";
	 std::cin >> spot;
	 std::cout << std::endl;

	 if(spot < 1 || spot > atoi(argv[1])*atoi(argv[1]))
	    std::cout << "You can't move there!" << std::endl;

	 if(spot==pokestop_rng) { //determines what happens when player lands on a pokestop
	    s.get_event();
	    s.set_pokeballs();
	    std::cout << "You have " << s.get_pokeballs() << " pokeballs!" << std::endl;
	    s.get_pokeballs();
	 }
	 if(spot==rock_rng) { //determines what happens when the player lands on geodude
	    char choice;
	    std::cout << "do you want to try to catch the pokemon? (y/n): ";
	    std::cin >> choice;
	    if(choice=='y')
	       r.catch_pokemon();
	    else {
	       std::cout << "The pokemon ran away!" << std::endl;
	       rock_rng = rand() % (atoi(argv[1])*atoi(argv[1])+1); //makes the geodude run away
	    } 

	 }
	 map[i][j]=0;
	 for(int i=0; i<(atoi(argv[1])*atoi(argv[1])); i++) {
	    map[i][j]=map[i][j]+1;
	    if(map[i][j]==rng)
	       std::cout << 's';

	    if(map[i][j]==pokestop_rng) {
#ifdef DEBUG
	       std::cout << "pokestop";
#endif
	    }
	    if(map[i][j]==cave_rng) {
#ifdef DEBUG
	       std::cout << "cave";
#endif
	    }
	    if(map[i][j]==rock_rng) {
#ifdef DEBUG
	       std::cout << "Geodude";
#endif
	    }
	    if(map[i][j]==spot) {
	       std::cout << 'x'; //shows the player's current location
	    }

	    std::cout << map[i][j] << ' ';
	    if(map[i][j] % (atoi(argv[1])) == 0)
	       std::cout << std::endl;
	 }
	 if(spot==pokestop_rng-1 || spot==pokestop_rng+1 || spot==pokestop_rng - (atoi(argv[1])) || spot==pokestop_rng + (atoi(argv[1])))
	    std::cout << "Fill up on Pokeballs" << std::endl; //percept for pokestop
	 std::cout << std::endl;

	 if(spot==cave_rng-1 || spot==cave_rng+1 || spot==cave_rng - (atoi(argv[1])) || spot==cave_rng + (atoi(argv[1])))
	    std::cout << "You see a precious stone nearby" << std::endl; //percept for cave
	 std::cout << std::endl;

	 if(spot==rock_rng-1 || spot==rock_rng+1 || spot==rock_rng - (atoi(argv[1])) || spot==rock_rng + (atoi(argv[1])))
	    std::cout << "Capture the Geodude nearby" << std::endl; //percept for geodude
	 std::cout << std::endl;
      }while(loop==true);
   }
   else {
      std::cout << "Commandline needs 2 arguments, a.out and a number greater than or equal to 3!" << std::endl;
   }
}

/* Function: get_location
 * Description: gets where the players is located
 * Parameters: argv[1], and map
 * Preconditions: map exists
 * Postconditions: none
 */
void location::get_location(char (*argv[1]), int *map) {
   int spot, i=0, j=0;
   std::cout << "Enter where you want to move: ";
   std::cin >> spot;
   if(spot < 1 || spot > (atoi(argv[1]))*(atoi(argv[1])))
      std::cout << "You can't move there!" << std::endl;
}

