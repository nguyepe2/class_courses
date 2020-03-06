#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;

class vehicle {
   protected:
      string id;
      int wheels;
      int toll;

   public:
      void set_id();
      string get_id();
      void set_wheels();
      int get_wheels();
      int get_toll();

};
#endif
