#include "vehicle2.h"
#include "bike2.h"
#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "how many bikes do you have?: ";
   cin >> n;
   vehicle v;
   bike *b=new bike[n];

   v.set_id();
   cout << v.get_id() << endl;
   v.set_wheels();
   cout << v.get_wheels() << endl;
   cout << "your toll is: " << v.get_toll() << endl;
   for(int i=0; i<n; i++) {
      cout << "bike " << i+1 << endl;
      b->set_pedals();

   }
   delete [] b;
}
