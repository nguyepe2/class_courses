#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int x;
	srand(time(NULL));

	x = rand() % 5;
	cout << "x = " << x << endl;
	if(x==1 or x==3 or x==5)
		cout << "I'm an odd number!" << endl;	
	else if(x==2 or x==4)
		cout << "I'm an even number!" << endl;
	else
		cout << "Bummer, I'm zero!" << endl;
/*	x = rand() % 5;
	cout << "x = " << x << endl;
*/
	return 0;
}
