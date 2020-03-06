#include <iostream>
#include <cmath>
#define NUM_BITS_IN_BYTE 8
using namespace std;
int main() {
	cout << "A char takes up " << sizeof(char)*NUM_BITS_IN_BYTE << " bits of memory" << endl;
	cout << "A int takes up " << sizeof(int)*8 << " bits of memory" << endl;
	cout << "A long takes up " << sizeof(long)*8 << " bits of memory" << endl;
	cout << "A short takes up " << sizeof(short)*8 << " bits of memory" << endl;
	cout << "A float takes up " << sizeof(float)*8 << " bits of memory" << endl;
	cout << "A double takes up " << sizeof(double)*8 << " bits of memory" << endl;
	cout << "A bool takes up " << sizeof(bool)*8 << " bits of memory" << endl;

	cout << "2^32 + 1 = " << pow(2,32)+1 << endl;
	cout << "5.0^3 = " << pow(5.0,3) << endl;
	cout << "square root of 25 is: " << sqrt(25) << endl;
	cout << "34.0 mod 5 is: " << 34 % 5 << endl;
	cout << "Absolute value of -50 is: " << abs(-50) << endl;
	cout << "Square root of 2^64 is: " << sqrt(pow(2,64)) << endl;
return 0;
}
