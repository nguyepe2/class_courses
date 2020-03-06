#include <iostream>
#include <cmath>
using namespace std;

int a;
int b;
int c;
int x;

main() {
	cout << "Enter a: ";
	   cin >> a;
	cout << "Enter b: ";
	   cin >> b;
	cout << "Enter c: ";
	   cin >> c;
	cout << -b + (sqrt(pow(b,2)-(4*a*c)))/(2*a) << endl;
return 0;
}
