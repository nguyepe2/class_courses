#include <iostream>
#include <cmath>
using namespace std;

double x;
double n;
double a;
double b;
double w;


//Name:f
//Description: Calculates the height of the rectangle 
//Pre Conditions: x value
//Post conditions: none
//Return: height of the rectangle

double f(double x) {
   
	return 2*x;
}

//Name: area
//Description: Calculates the area under the curve
//Pre Conditions: value of a, value of b, value of n
//Post Conditions: none
//Return: The area under the curve

double area(double a, double b, double n) {
	//calculate and return the area under the function
	return w*f(x);
}
main(){
   	w=(b-a)/n;
   	cout << "Enter x: ";
	   cin >> x;
	cout << "Enter the number of rectangles (n): ";
	   cin >> n;
	cout << "Enter the beginning x value (a): ";
	   cin >> a;
	cout << "Enter the ending x value (b): ";
	   cin >> b;
	cout << w*f(x);
	//cout << 2*x << endl;
	//cout << ((b-a)/n)*(2*x) << endl;

	double f(double x);
	double area(double a, double b, double n);
	
return 0;
}














