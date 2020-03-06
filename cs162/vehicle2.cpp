#include "vehicle2.h"
#include <iostream>
#include <string>
using namespace std;

void vehicle::set_id() {
  cout << "Enter the id: ";
    cin >> id;
      
}

string vehicle::get_id() {
  return id;
}

void vehicle::set_wheels() {
  cout << "Enter the amount of wheels: ";
    cin >> wheels;
      
}

int vehicle::get_wheels() {
  return wheels;
}

int vehicle::get_toll() {
  toll=4*wheels;
  return toll;
}
