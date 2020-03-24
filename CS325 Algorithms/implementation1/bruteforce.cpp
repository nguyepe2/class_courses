#include <iostream>
#include <fstream>

using namespace std;

fstream infile("example.input");

int main() {
   int first[100000];
   int second[100000];
   int x, y, i=0, j;

   while(infile >> x >> y) {
     first[i]=x;
     second[i]=y;
     i++;
   }
   
   int count=sizeof(first)/sizeof(first[0])   
   for(j=0; j<(sizeof(first)/sizeof(first[0])); j++) {
     cout << first[j] << '\n';
   }
     

   return 0;
}
