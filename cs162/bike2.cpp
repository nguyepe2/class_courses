#include "bike2.h"
#include "vehicle2.h"
#include <iostream>
using namespace std;

void bike::set_pedals() {
   vehicle v;
   do{
      cout << "Does your bike have pedals below the rider? (1=yes, 2=no): ";
      cin >> pedals;
      if(pedals==1) {
	 cout << "Your bike has pedals below the rider" << endl;
	 cout << "Your toll is: " << get_toll() << endl;
      }
      else if(pedals==2) {
	 cout << "Your bike has pedals in front of the rider" << endl;
	 cout << "Your toll is: " << 2*4 << endl;
      }
      else
	 cout << "Your answer is not valid, please enter either 1 or 2" << endl;
   }while(pedals < 1 || pedals > 2);
}

int bike::get_pedals() {
   return pedals;
}

int bike::get_toll() {
   toll=0;
   return toll;
}
