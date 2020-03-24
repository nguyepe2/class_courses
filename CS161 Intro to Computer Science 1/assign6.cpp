/*
 * Program: assign6.cpp
 * Author: Peter Nguyen
 * Date: 3/19/17
 * Description: Reads output from a file, and randomly assigns words to the story
 * Input: Which story and the word file
 * Output: The story with filled in blanks
 */
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
 * Function: rng
 * Description: Creates a randomly generated number
 * Parameters: the amount of nouns, verbs, and adjectives
 * Pre-conditions: The number of nouns, verbs, and adjectives exists
 * Post-conditions: None
 * Return: the variable rng contains a randomly generated number
 */
int rng(int n) {
  int random=rand() % n;
}

/*
 * Function: story1
 * Description: assigns words to story 1
 * Parameters: None
 * Preconditions: The word file exists
 * Postconditions: None
 * Return: Story1 with the blanks filled in
 */
char story1() {
   char word[30];
   char noun[25][30];
   char verb[25][30];
   char adjective[25][30];
   int n,v,a;
   for(int i=0; i<3; i++) 
      for(int j=0; j<25; j++) {
     //   cin.getline(word,30);
        cin >> word;
	if(word[0]=='n') {
	 //  cin.ignore(5);
	//   cin.getline(word,30);
	   cin >> word;
	   //noun[i][j]=*word;
	   strcpy(noun[n],word);
	   n++;
	   //cout << word << "     ";
	}
	else if(word[0]=='v') {
	  cin>> word;
	  strcpy(verb[v],word);
	  v++;
	}
	else if(word[0]=='a') {
	  cin >> word;
	  strcpy(adjective[a],word);
	  a++;
	}
       }
   
cout << "Most doctors agree that bicycle "; cout << verb[0] <<"ing is a/an "; cout << adjective[0] << " form of exercise. "; cout << verb[1] <<"ing a bicycle enables you to develop your "; cout << noun[0] << " muscles, as well as increase the rate of your "; cout << noun[1];
cout << " beat. More "; cout << noun[2] <<"s around the world "; cout << verb[2] <<" bicycles than drive "; cout << noun[3] <<"s. ";
"No matter what kind of "; cout << noun[4] << " you "; cout << verb[3] <<", always be sure to wear a/an "; cout << adjective[1] << " helmet. Make sure to have "; 
cout << adjective[2] <<" reflectors too!" << endl;
}

/*
 * Function: story3
 * Description: assigns words to story 3
 * Parameters: None
 * Preconditions: The word file exists
 * Postconditions: None
 * Return: Story3 with the blanks filled in
 */
char story2() {
cout << "Yesterday, <noun> and I went to the park. On our way to the <adjective> park, we saw a "
   "<adjective> <noun> on a bike. We also saw big <adjective> balloons tied to a <noun>. Once"
   " we got to the <adjective> park, the sky turned <adjective>. It started to <verb> and <verb>."
   " <noun> and I <verb> all the way home. Tomorrow we will try to go to the <adjective> park "
   "again and hope it doesn’t <verb>." << endl;
}


/*
 * Function: story3
 * Description: assigns words to story 3
 * Parameters: None
 * Preconditions: The word file exists
 * Postconditions: None
 * Return: Story3 with the blanks filled in
 */
char story3() {
   cout << "Spring break 2017, oh how I have been waiting for you! Spring break is when you go to some "
   "<adjective> place to spend time with <noun>. Getting to <noun> is going to take <adjective> "
   "hours. My favorite part of spring break is <verb/ing> in the <noun>. During spring break, "
   "<noun> and I plan to <verb> all the way to <noun>. After spring break, I will be ready to return "
   "to <noun> and <verb> hard to finish <noun>. Thanks spring break 2017!" << endl;

}

int main(int argc, char *argv[]) {
  if(argv[1][0]=='1' && argv[1][1]<' ') {
    story1();
  }
  else if(argv[1][0]=='2' && argv[1][1]<' ') {
    story2();
  }
  else if(argv[1][0]=='3' && argv[1][1]<' ') {
    story3();
  }
  else
     cout << "Enter a number 1-3 in the command line" << endl;
return 0;
}
