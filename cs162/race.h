/*
 * This file contains the function execute_race.
 * Include this file to allow you to perform
 * races between your creatures.
 *
 * You will need to have the following functions defined:
 *
 *			In the car class (and possibly subclasses):
 *				Creature * getDriver() //pointer to creature driver of vehicle
 *				string getvehicle() // string describing the vehicle
 *				int getDistance()   // how far we move per second
 *
 *			In the creature class (and possibly subclasses):
 *				string getSpecies()    // string describing the species
 *				int getHitpoints()     // getter for the creature hitpoints
 *				void setHitpoints(int) // setter for the creature hitpoints
 *				int getDamage()        // how much damage we did
 */

#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "creature.h"
#include "vehicle.h"

/*
 * These macros can be adjusted to change
 * the time the game takes to run.
 */
#define SEC_TIME_LIMIT 120 // game will quit if no winner after this time is up
#define RACE_DISTANCE 1000 // distance to reach the food
#define VICTORY_FOOD  1000 // the amount of food
#define EAT_PER_ROUND 0.05 // the percent of their bodyweight
                           // a creature can eat per second

using std::cout;
using std::endl;
using std::flush;
using std::string;

/*
 * This function takes as input two pointers
 * to objects of the creature_car class (or sub-classes).
 * It will return the pointer to the winning creature_car.
 */
creature * execute_race(vehicle *a, vehicle *b)
{
	int remaining_food = VICTORY_FOOD;
	int race_prog_a = 0;
	int race_prog_b = 0;

	bool finished_a = false;
	bool finished_b = false;

	string species_a = a->getDriver()->getSpecies();
	string species_b = b->getDriver()->getSpecies();

	int limit = 0;
	int temp = 0;
	int random = 0;

	// initialize random numbers
	srand(time(NULL));

	// Print out who is racing...
	cout << "Car A: " << species_a;
	cout << " in the " << a->getvehicle() << endl;

	cout << "Car B: " << species_b;
	cout << " in the " << b->getvehicle() << endl;

	cout << endl;

	cout << "Race will begin in " << flush;
	sleep(2);
	cout << "3, " << flush;
	sleep(1);
	cout << "2, " << flush;
	sleep(1);
	cout << "1..." << flush;
	sleep(1);
	cout << "GO!" << endl << endl;

	// Start Race!
	while (++limit < SEC_TIME_LIMIT) {
		sleep(1);
		cout << endl;
		cout << endl;
		cout << endl;

		// Racer A
		if (!finished_a) { // Round One: Racing
			race_prog_a += a->getDistance();
			if (race_prog_a >= RACE_DISTANCE) {
				finished_a = true;
				cout << "Racer A (" << species_a << ") has reached the food." << endl;
			} else {
				cout << "Racer A (" << species_a << ") has completed "
					 << race_prog_a * 100 / RACE_DISTANCE << "% of the race." << endl;
			}
		} else if (remaining_food > 0) { // Round Two: Eating
			random = rand() % 100;
			if (random == 99) {
				cout << "Perfect piece of food!" << endl;
				temp = a->getDriver()->getHitpoints() * EAT_PER_ROUND * 20;
			} else if (random > 90) 
				cout << "Good piece of food!" << endl;
				temp = a->getDriver()->getHitpoints() * EAT_PER_ROUND * 5;
			} else {
				temp = a->getDriver()->getHitpoints() * EAT_PER_ROUND;
			}
			if (temp == 0) {
				temp = 1; // to help out the little guys
			}
			if (temp >= remaining_food) {
				a->getDriver()->setHitpoints(a->getDriver()->getHitpoints() + remaining_food);
				remaining_food = 0;
				cout << "Racer A (" << species_a << ") has eaten the last of the food"
					 << " and now has " << a->getDriver()->getHitpoints() << " hitpoints." << endl;
			} else {
				a->getDriver()->setHitpoints(a->getDriver()->getHitpoints() + temp);
				remaining_food -= temp;
				cout << "Racer A (" << species_a << ") has eaten " << temp
					 << " and now has " << a->getDriver()->getHitpoints() << " hitpoints." << endl;
			}
		} else if (limit % 2 == 0) { // Round Three: Fighting
			sleep(1); // for dramatic effect
			temp = a->getDriver()->getDamage();
			if (temp >= b->getDriver()->getHitpoints()) {
				cout << "Racer A (" << species_a << ") has defeated Racer B (" << species_b
					 << ") with a hit for " << temp << " damage!" << endl;
				return a->getDriver();
			} else {
				b->getDriver()->setHitpoints(b->getDriver()->getHitpoints() - temp);
				cout << "Racer A (" << species_a << ") has hit Racer B (" << species_b
					 << ") for " << temp << " damage. Racer B now has "
					 << b->getDriver()->getHitpoints() << " hitpoints." << endl;
			}
		}

		// Racer B
		if (!finished_b) { // Round One: Racing
			race_prog_b += b->getDistance();
			if (race_prog_b >= RACE_DISTANCE) {
				finished_b = true;
				cout << "Racer B (" << species_b << ") has reached the food." << endl;
			} else {
				cout << "Racer B (" << species_b << ") has completed "
					 << race_prog_b * 100 / RACE_DISTANCE << "% of the race." << endl;
			}
		} else if (remaining_food > 0) { // Round Two: Eating
			random = rand() % 100;
			if (random == 99) {
				cout << "Perfect piece of food!" << endl;
				temp = b->getDriver()->getHitpoints() * EAT_PER_ROUND * 20;
			} else if (random > 90) {
				cout << "Good piece of food!" << endl;
				temp = b->getDriver()->getHitpoints() * EAT_PER_ROUND * 5;
			} else {
				temp = b->getDriver()->getHitpoints() * EAT_PER_ROUND;
			}
			if (temp == 0) {
				temp = 1; // to help out the little guys
			}
			if (temp >= remaining_food) {
				b->getDriver()->setHitpoints(b->getDriver()->getHitpoints() + remaining_food);
				remaining_food = 0;
				cout << "Racer B (" << species_b << ") has eaten the last of the food"
					 << " and now has " << b->getDriver()->getHitpoints() << " hitpoints." << endl;
			} else {
				b->getDriver()->setHitpoints(b->getDriver()->getHitpoints() + temp);
				remaining_food -= temp;
				cout << "Racer B (" << species_b << ") has eaten " << temp
					 << " and now has " << b->getDriver()->getHitpoints() << " hitpoints." << endl;
			}
		} else if (limit % 2 == 1) { // Round Three: Fighting
			sleep(1); // for dramatic effect
			temp = b->getDriver()->getDamage();
			if (temp >= a->getDriver()->getHitpoints()) {
				cout << "Racer B (" << species_b << ") has defeated Racer A (" << species_a
					 << ") with a hit for " << temp << "damage!" << endl;
				return b->getDriver();
			} else {
				a->getDriver()->setHitpoints(a->getDriver()->getHitpoints() - temp);
				cout << "Racer B (" << species_b << ") has hit Racer A (" << species_a
					 << ") for " << temp << " damage. Racer A now has "
					 << a->getDriver()->getHitpoints() << " hitpoints." << endl;
			}
		}
	}
	// ran out of time
	if (a->getDriver()->getHitpoints() > b->getDriver()->getHitpoints()) {
		cout << "Time expired. Racer A has more hitpoints left." << endl;
		return a->getDriver();
	} else {
		cout << "Time expired. Racer B has more hitpoints left." << endl;
		return b->getDriver();
	}
}
