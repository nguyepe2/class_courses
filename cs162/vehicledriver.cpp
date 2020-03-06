/*#include "creature.h"
#include "human.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
#include "elf.h"
#include "vehicle.h"
#include "skateboard.h"
#include "motorcycle.h"
#include "racecar.h"
#include "bike.h"
*/
#include "race.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
  vehicle v;
  skateboard s;
  motorcycle m;
  racecar r;
  bike b;

  s.set_wheels(4);
  s.set_speed(10);
  s.set_motor(false);

  m.set_wheels(2);
  m.set_speed(50);
  m.set_motor(true);

  r.set_wheels(4);
  r.set_speed(200);
  r.set_motor(true);

  b.set_wheels(2);
  b.set_speed(20);
  b.set_motor(false);
  
  cout << s.getDescription() << endl;
  cout << "skateboard wheels: " << s.get_wheels() << endl;
  cout << "skateboard speed: " << s.get_speed() << endl;
  cout << "Motor?: " << s.get_motor() << endl;
  cout << endl;
  
  cout << m.getDescription() << endl;
  cout << "motorcycle wheels: " << m.get_wheels() << endl;
  cout << "motorcycle speed: " << m.get_speed() << endl;
  cout << "Motor?: " << m.get_motor() << endl;
  cout << endl;

  cout << r.getDescription() << endl;
  cout << "racecar wheels: " << r.get_wheels() << endl;
  cout << "racecar speed: " << r.get_speed() << endl;
  cout << "Motor?: " << r.get_motor() << endl;
  cout << endl;

  cout << b.getDescription() << endl;
  cout << "bike wheels: " << b.get_wheels() << endl;
  cout << "bike speed: " << b.get_speed() << endl;
  cout << "Motor?: " << b.get_motor() << endl;
  cout << endl;

  if(m > s)
     cout << "motorcycle is faster than skateboard" << endl;
  else
     cout << "skateboard is faster than motorcycle" << endl;
}
