#include <iostream>
#include <string>
using namespace std;
int main() {
	string name;
	string guess;
	int choice;
	bool got_it;
	
do{
	cout << "Choose a number to learn more about the mystery TA! Enter 1 for the TA's hair color, 2 for their gender, and 3 for their class standing. Once you're ready to guess enter 0 to input the TA's name: ";
	cin >> choice;
	if(choice==1) {
		cout << "The TA has black hair" << endl;
	}
	else if(choice==2) { 
		cout << "The TA is female" << endl;
	}
	else if(choice==3) {
		cout << "The TA is junior at OSU" << endl;
	}
	else if(choice==0) {
		cout << "What's the name of the TA?: ";
		cin >> guess;
		if(guess=="Megan" or guess=="megan") {
			cout << "You got it right!" << endl;
			got_it=true;
		}
		else {
			cout << "Sorry, that's not the correct answer" << endl;
			got_it==false;
		}
	}
}while(got_it==false);

/* if(guess=="Megan") {
	cout << "You got it right!" << endl;
	got_it==true;
}
else {
	cout << "Sorry, that's not the correct answer" << endl;
	got_it==false;
}
*/
return 0;
}
