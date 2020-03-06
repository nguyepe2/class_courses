#include <iostream>
#include <cmath>
#define PROMPT "Please enter a whole number: "
#define NOT_PRIME "The number is not a prime number. "
#define PRIME "The number is a prime number. "
using namespace std;
using std::cout;
using std::cin;

void is_prime(int*);

int main(){
    int number; /* number provided by user */
    cout << PROMPT;  /* promt user */
    cin >> number;  /* wait for user input */
    is_prime(&number);  /*determine if number prime or not*/
    
        return 0;     /* exit program */
}


void is_prime(int *number){
   int i=2;
/*    if((*number==0) || (*number==1) || (*number==2) ||(*number==3))
	cout << PRIME << *number << endl;
*/	
    for(i; i < *number-1; i++) {
      if((*number % i) == 0) {
	 cout << NOT_PRIME << endl;
	 break; 
      }
         
      if(*number%i!=0) {
//	cout << PRIME << endl;
       //break;
      }
    }
    if((*number % i!=0) || (*number == 2))
       cout << PRIME << endl;
}
/* Prime numbers are defined as any number greater
 * * than one that is only divisible by one and itself.
 * * Dividing the number by two shortens the time it 
 * * takes to complete. */


/*void is_prime(int *number){
    for(int i = 3; i < *number/2; ++i)
              if(*number/i == 0 ){    // if divisible */
/*	                cout << NOT_PRIME << number << endl; // not prime */
/*	                return;        // exit program */
//	             }
    /* if number is not divisible by anything
     *      * than it must be prime */
/*    cout << PRIME << *number << endl;
    cout << "This is what the variable number is: " << *number << endl;
}
*/
