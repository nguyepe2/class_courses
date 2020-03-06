/*
 ** Program: assign1.cpp
 ** Author: Peter Nguyen
 ** Date: 1/15/2017
 ** Description: Shows the user what the minimum and maximum values are for signed and unsigned characters and for different numbers of bits
 ** Input: The number of bits
 ** Output: Minimum and Maximum signed and unsigned number for the user specified amount of bits
 */
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main() {
	int bits;
	cout << endl;
	cout << SCHAR_MIN << " is the smallest signed character" << endl; 
	cout << SCHAR_MAX << " is the largest signed character" << endl;
	cout << "0" << " is the smallest unsigned character" << endl;
	cout << UCHAR_MAX << " is the largest unsigned character" << endl;
	cout << "0" << " is the smallest unsigned long" << endl;
	cout << ULONG_MAX << " is the largest unsigned long" << endl;
	cout << LONG_MIN << " is the smallest signed long" << endl;
	cout << LONG_MAX << " is the largest signed long" << endl;
	cout << "0" << " is the smallest unsigned short" << endl;
	cout << USHRT_MAX << " is the largest unsigned short" << endl;
	cout << SHRT_MIN << " is the smallest signed short" << endl;
	cout << SHRT_MAX << " is the largest signed short" << endl;
	cout << endl;

	cout << "The maximum signed number in one byte is: " << pow(2,7)-1 << endl; 
	cout << "The minimum signed number in one byte is: " << pow(-2,7) << endl;
	cout << "The maximum unsigned number in one byte is: "<< pow(2,8)-1 << endl;
	cout << endl;
	
	cout << "Enter the number of bits: ";
	cin >> bits;
	cout << "The maximum unsigned number for " << bits << " bits is: " << pow(2,bits) - 1 << endl;
	cout << "The minimum unsigned number for " << bits << " bits is: " << "0" << endl;
	cout << "The maximum signed number for " << bits << " bits is: " << pow(2,bits-1) - 1 << endl;
	cout << "The minimum signed number for " << bits << " bits is: " << -pow(2,bits-1) << endl;
	return 0;
}
