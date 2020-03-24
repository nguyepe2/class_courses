/*
 *Program: Assign2.cpp
 *Author: Peter Nguyen
 *Date: 1/22/17
 *Description: A text-based adveture game where the user is given multiple decisions that can affect whether they live or die
 *Input: A number, either 1 or 2
 *Output: The consequence of the action the user took
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

main() {
	int choice;
	int x;
	srand(time(NULL));

	cout << "Welcome to the adventure!" << endl;
	cout << "To go right enter 1, to go left enter 2: ";
	cin >> choice;

	if(choice==1) {
		cout << "You walk down a dirt path, admiring the scenery." << endl;
		cout << "To go right enter 1, to go left enter 2: ";
		cin >> choice;
	}
	
		if(choice==1) {
			cout << "As you walk along the path, you encounter a large clearing." << endl;
			cout << "To go right enter 1, to go left enter 2: ";
			cin >> choice;
		}
			if(choice==1) {
				cout << "Suddenly, you encounter an angry animal." << endl;
				cout << "To run away enter 1, to hide enter 2: ";
				cin >> choice;
			}
				if(choice==1) {
					cout << "The beast is right behind you when you realize a river is blocking your escape route." << endl;
					cout << "To attempt to swim enter 1, to try to fight enter 2: ";
					cin >> choice;
				}
					if(choice==1) {
						x = rand() % 10;
						if(x > 5) {
							cout << "Luck was on your side. You successfully crossed the river. Congratulations, you won the game!" << endl;
						}
						else {
							cout << "Luck was not on your side. You drowned while trying to cross the river." << endl;
						}
					}
/*					else if(choice==2)  {
						cout << "The beast killed you." << endl;
					}
*/
	else {
		cout << "You walked off a cliff and died." << endl;
	}
					cout << "Would you like to play again? Enter 1 for yes, and enter 2 for no: ";
					cin >> choice;
					if(choice==1) {
						main();
					}
					else {
						cout << "Thanks for playing!" << endl;
					}
					
	return 0;
}
