#include "vehicle.h"
#include <iostream>
using namespace std;


void vehicle::set_wheels(int w) {
  wheels=w;
}

int vehicle::get_wheels() {
  return wheels;
}

void vehicle::set_speed(int s) {
  speed=s;
}

int vehicle::get_speed() {
  return speed;
}

void vehicle::set_motor(bool m) {
  motor=m;
}

int vehicle::get_motor() { 
  return motor;
}

bool vehicle::operator>(const vehicle& other) {
  return this->speed>other.speed;
}

creature * driver

creature * getDriver()
     
void setDriver(creature *) {

}
     
int getDistance() {

}
     
string getVehicle() {

}
