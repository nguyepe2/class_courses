/* Program: run_facts.cpp
 * Author: Peter Nguyen
 * Date: 4/16/17
 * Description: Calls all the functions 
 * Input: commandline arguments from the user
 * Output: Either an error message or the results of all the functions it calls
 */

#include "state_facts.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

//bool is_valid_arguments(char *[], int);
//state * create_states(int);


/*bool is_valid_arguments(char *[], int) {

   if(argc !=5){
      cout << "Incorrect number of args. There must be 5 arguments. Remember that there must be a -s and -f with a positive integer after " 
	 "-s and the name of a text file after -f " << endl;
      return 0;
   } 
   for(int i=0; i<5; i++) {
	 if(argv[i][i-1]=='-' && argv[i][i]== 's') {
	    cout << "-s is there" << endl;
	    do{
	    if(atoi(argv[i+1]) <= 0) {
	       cout << "invalid number" << endl;
	       cout << "Enter a number greater than 0: ";
	       cin >> argv[i+1];
	    }
	    }while(atoi(argv[i+1]) <=0);
	    int num=atoi(argv[i+1]);
	    return num;
	 }
	 if(argv[i][i]=='-' && argv[i][i+1]== 'f') {
	   cout << "-f is there" << endl;
	   ifstream file;
	   file.open(argv[i+2]);
	   if(file.fail())
	      cout << "The file failed to open!" << endl;
	 }
   }
}
*/
int main(int argc, char **argv) {
   char list[256];
   bool a=false;
   if(argc !=5){
      cout << "Incorrect number of args. There must be 5 arguments. Remember that there must be a -s and -f with a positive integer after " 
	 "-s and the name of a text file after -f " << endl;
      return 0;
   } 
   for(int i=0; i<5; i++) {
	 if(argv[i][i-1]=='-' && argv[i][i]== 's') {
	    cout << "-s is there" << endl;
	    do{
	    if(atoi(argv[i+1]) <= 0) {
	       cout << "invalid number" << endl;
	       cout << "Enter a number greater than 0: ";
	       cin >> argv[i+1];
	    }
	    }while(atoi(argv[i+1]) <=0);
	 }
	 if(argv[i][i]=='-' && argv[i][i+1]== 'f') {
	   cout << "-f is there" << endl;
	   ifstream file;
	   cout << "name of text file: " << argv[i+2] << endl;
	   file.open(argv[i+2]);
	   //do{
	   if(file.fail())
	      do{
	      cout << "The file failed to open!" << endl;
	      cout << "Please enter a valid file name ";
	      cin >> list;
	      file.open(list);
	      if(file.is_open()) {
	        a==true;
	      }
	   }while(a==false);
	 }
   }
}
