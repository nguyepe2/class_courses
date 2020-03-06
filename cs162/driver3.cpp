/* Program Filename: driver3.cpp
 * Author: Peter Nguyen
 * Date: 5/14/2017
 * Description: A program that allows the user to make creatures battle each other
 * Input: numbers, names
 * Output: the battle stuff
 */
#include "world.h"
#include "creature.h"
#include "human.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
#include "elf.h"
#include "gnome.h"
#include <iostream>
using namespace std;

int main() {
world w;
creature c;
human h;
demon d;
balrog b;
cyberdemon y;
elf e;
gnome g;


c.getSpecies(0);
cout << c.getSpecies(0) << endl;
w.set_money();
cout << w.get_money() << endl;
w.set_name_h();

c.getSpecies(2);
cout << c.getSpecies(2) << endl;
w.set_name_b();

c.getSpecies(1);
cout << c.getSpecies(1) << endl;
w.set_name_c();

c.getSpecies(3);
cout << c.getSpecies(3) << endl;
w.set_name_e();

c.getSpecies(4);
cout << c.getSpecies(4) << endl;
w.set_name_g();

w.battle();
}
