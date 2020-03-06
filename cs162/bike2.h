#include <iostream>
#include "vehicle2.h"
using namespace std;

class bike:public vehicle {
   private:
      int pedals;
      int toll;

   public:
      void set_pedals();
      int get_pedals();
      int get_toll();


};
