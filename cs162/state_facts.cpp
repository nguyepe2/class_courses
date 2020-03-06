#include "state_facts.h"
#include <iostream>


/*Function: is_valid_arguments
 *Description: checks command line arguments and makes sure that they're valid inputs
 *Parameters: argv array and number of arguments (argc) 
 *Preconditions: None
 *Postcondtions: values within argv are valid
 *Return: None
 */
bool is_valid_arguments(char *[], int); /*{

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

/*Function: create_states
 *Description: create an array of state structs
 *Parameters: the number of states
 *Preconditions: valid number of states
 *Postcondtions: A certain amount of state structs are created
 *Return: None
 */
state * create_states(int);

/*Function: get_state_data
 *Description: retrieves data about a state
 *Parameters: struct array, number of states, file name
 *Preconditions: command line is valid, struct for the state exists, file exists
 *Postcondtions: None
 *Return: None
 */
void get_state_data(state *, int, ifstream &);

/*Function: create_counties
 *Description: create an array of county structs
 *Parameters: number of counties
 *Preconditions: valid number of counties
 *Postcondtions: Stores county data in county structs
 *Return: None
 */
county * create_counties(int);

/*Function: get_county_data
 *Description: retrieves data about a county
 *Parameters: struct array, number of counties, file name
 *Preconditions: command line is valid, struct for counties exists, file exists
 *Postcondtions: None
 *Return: None
 */
void get_county_data(county *, int, ifstream &);

/*Function: delete_info
 *Description: Deletes arrays
 *Parameters: state struct, number of counties
 *Preconditions: state struct exists, number of counties is valid
 *Postcondtions: arrays are deleted
 *Return: None
 */
void delete_info(state **, int);

