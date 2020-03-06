/*Program: assign4.cpp
 *Author: Peter Nguyen
 *Date: 2/19/2017
 *Description: A game that plays similiarly to wheel of fortune
 *Input: The secret message, integers 1-3 for deciding which option to take, letters when guessing the letters of the phrase, and strings when guessing the phrase
 *Output: A copy of the secret message and the updated copy for each correct guess, money for each player, the number they rolled, message with winning player
 */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void get_string(string*);
void set_replace_string(string,string*);  
int get_search_replace(string,string*);
int rand_num(string, string*);
void options(string*, string*, char*);
void players(int);
int rounds(int);
int vowel_guess(string, string*);
int guess_phrase(string, string*, char*);

/*Function: main
 *Description: contains all the functions
 *Parameters: None
 *Preconditions: None
 *Postconditions: None
 *Return: 0
 */
int main() {
   string s,p;
   int i,player_num,num_rounds;
   char a;
   players(player_num);
   rounds(num_rounds);
   get_string(&s);
   set_replace_string(s,&p);
   options(&s,&p, &a);
   /*   get_string(&s);
	set_replace_string(s,&p);
	get_search_replace(s,p);
	cout << p << endl;
	rand_num();
	*/
   return 0;
}

/*Function: get_string
 *Description: takes the input from the user and stores that input as the secret message
 *Parameters: the secret message
 *Preconditions: A string
 *Postcondtions: The secret message must be a string
 *Return: None
 */
void get_string(string* s) {
   cout << "Enter any string: ";
   cin.ignore();
   getline(cin,*s); //stores the secret phrase in s
   system("clear"); // hides the secret phrase
}

/*Function: set_replace_string
 *Description: Makes a copy of the original string (s) and turns all the charaters in s into dahes, and then stores that string into variable p
 *Parameters: secret message and a copy of the secret messsage
 *Preconditions: the secret message must be a string
 *Postconditions: the copy of the secret message must be a string
 *Return: None
 */
void set_replace_string(string s,string*p) {
   *p=s; //creates a copy of s and stores it in p
   for(int i=0; s.size()>i; i++) {
      if(s[i]!=' ') {
	 (*p)[i]='-'; //rewrites characters in s as dashed lines
      }
   }
}

/*Function: get_search_replace
 *Description: allows the user to guess consonants of the secret phrase and amends the secret phrase as the user guesses correctly
 *Parameters: secret message and a copy of the secret message
 *Preconditions: secret message and the copy of the secret message must be strings  
 *Postconditions: The copy of the secret message must be a string
 *Return: An updated version of the copy of the secret message as the user correctly guesses the letters in the secret message
 */
int get_search_replace(string s,string *p) {
   char a;
   int loop=1;
      do{      //an attempt to allow the user to guess multiple times if they guessed a letter correctly, doesn't work for some reason
   cout << *p << endl;
      cout << "Guess a letter: ";	
      cin >> a;
      for(int i=0; s.size() > i; i++) {
      if(s[i]==a) {
	 (*p)[i]=a;
	 cout << *p << endl;
	   loop=1;
      }
       else
          loop=2;
      }//while(loop==1);
/*      if(s==p) {
      cout <<"Puzzle solved!" << endl;
      loop=2;
      return 2;
      } */
}while(loop==1);
}

/*Function: rand_num
 *Description: Randomly generates a number that will be used to determine how much money a player can make or whether or not they lose their turn
 *Parameters: secret message and a copy of the secret message
 *Preconditions: Secret message and its copy are strings
 *Postcondition: the variable rng is a integer between 0 and 21
 *Return: the value of rng and what rolls of 0 and 21 mean for the player
 */
int rand_num(string s, string *p) {
   int rng; //rng is the name of the randomly generated number
   srand(time(NULL));
   rng=rand() % 22; //generates a random number between 0 and 21
   cout << "The number you rolled is: " << rng << endl;
   if(rng!=0 and rng!=21) {
      get_search_replace(s,p);	
   }
   else if(rng==0){
   cout << "Bankrupt! You've lost your turn" << endl;
   }
   else if(rng==21) {
   cout << "Sorry, you've lost your turn!" << endl;
   }
   return rng;
}

/*Function: options
 *Description: Gives the user the options of guessing a consonant, buying a vowel, or guessing the secret phrase
 *Parameters: secret message, copy of the secret message, and value within a letter guess (*a)
 *Preconditions: Secret message is a string
 *Postconditions: None 
 *Return: None
 */
void options(string *s, string *p, char *a) {
   int choice;
   cout << "The message is: " << *p << endl;
   cout << "Enter '1' if you want to spin the wheel, '2' if you want to buy a vowel, '3' if you want to guess the secret phase: ";
   cin >> choice;
   if(choice==1) {
      rand_num(*s,p);
   }
   else if(choice==2) {
      vowel_guess(*s,p);
   }
   else if(choice==3) {
      guess_phrase(*s,p,a);
   }
}

/*Function: vowel_guess
 *Description: Allows the user to guess a vowel for the secret phrase
 *Parameters: secret phrase and copy of the secret phrase
 *Preconditions: Secret message and its copy are strings
 *Postconditions: None
 *Return: updated secret message copy
 */
int vowel_guess(string s, string *p) {
char a;
cout << "Enter a vowel: ";
char vowel;
cin >> a;
vowel=a;
/*if(vowel=="a" or vowel=="e" or vowel=="i" or vowel=="o" or vowel=="u") {
      for(int i=0; s.size() > i; i++) {
      if(s[i]==vowel) {
	 (*p)[i]=vowel;
	 cout << *p << endl;
}
}
} */
}

/*Function: guess_phrase
 *Description: Allow the user to guess the secret message
 *Parameters: secret message, copy of secret message, and value within a letter guess
 *Preconditions: Secret message and its copy are strings
 *Postconditions: None
 *Return: whether or not the user guessed the phrase correctly
 */
int guess_phrase(string s, string *p, char* a) {
string guess_message;
cout << *p << endl;
cout << "What's the phrase?: ";
cin >> guess_message;
if(guess_message==s) { //only seems to work for single word phrases
	cout << "Congratulations, you got the message right!" << endl;
}
else
   cout << "Sorry, your guess was incorrect. " << endl;
}

/*Function: players
 *Description: counts the number of players
 *Parameters: the number of players
 *Preconditions: number of players must be a positive integer
 *Postconditions: None
 *Return: None
 */
void players(int player_num) {
cout << "How many players do you have?: ";
cin >> player_num;
}

/*Function: rounds
 *Description: counts the amount of rounds
 *Parameters: the number of rounds
 *Preconditions: number of rounds must be a positive integer
 *Postconditions: None
 *Return: None
 */
int rounds(int num_rounds) {
cout << "How many rounds do you want to play for?: ";
cin >> num_rounds;
}
