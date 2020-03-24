#include <iostream>
using namespace std;
/*void create_mem1(int ** p){

}
void create_mem(int *&p){

}
void create_mem2(){
*/
/*int n=5;
int a[n];
int *p;
p=new int[n];
cout << p << endl;
delete [] p;

}
*/
int main(){

/*	int * point1 = NULL;
	int * point2 = NULL;
	int * point3 = NULL;
	
	create_mem1(&point1);
	cout << *point1 << endl;

	create_mem(point2);
	cout << *point2 << endl;
*/
//	create_mem2();

	int n=5;
//	int a[n]
	int *p;
	p=new int[n];
	cout << "Enter an integer: ";
	cin >> p[0];
	cout << "First slot in the array: " << p[0] << endl;
	cout << p << endl;
	delete [] p;
	return 0;

}
