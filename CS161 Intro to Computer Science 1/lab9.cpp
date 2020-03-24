#include <iostream>

using namespace std;

#define COLS 3
void towers(int disks, int b[][COLS], int from_col, int to_col, int spare);
void print_array(int array); 
/*int print_array() {
   for(int j=0; j<3; j++) {
      cout << array[j][0];
      cout << array[j][1];
      cout << array[j][2] << endl;
   }
}
*/

/*towers() {
if(disks >= 1)
   towers(disks-1, b, from_col, spare, to_col)
      
}
*/

main() {
int array[3][COLS] = {{ 1 , 0 , 0 },
   		      { 2 , 0 , 0 },
		      { 3 , 0 , 0 }};

//for(int i=0; i<3; i++)
   for(int j=0; j<3; j++) {
      cout << array[j][0];
      cout << array[j][1];
      cout << array[j][2] << endl;
   }
   
}
