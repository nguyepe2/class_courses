#include "cart.h"
#include "structs.h"
#include "patron.h"
#include "librarian.h"
#include "library.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/* Function: cart()
 * Description: sets the number of books to 0
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: books are set to 0
 */
cart::cart() {
  books=NULL;
  num_books=0;
}

/* Function: set_num_books
 * Description: mutator function that sets the value of the variable num_books
 * Parameters: an integer n
 * Preconditions: none
 * Postconditions: num_books is set to the value of n
 */
void cart::set_num_books(const int n) {
  num_books=n;
}

/* Function: get_num_books
 * Description: accessor function that retrieves the variable num_books
 * Parameters: none
 * Precondtions: num_books exists
 * Postconditions: none
 */
int cart::get_num_books() const {
  return num_books;
}

/* Function: get_books
 * Description: accessor function that retrieves the variable books
 * Parameters: none
 * Preconditions: books exists
 * Postconditions: none
 */
book*cart::get_books() const {
  return books;
}

void /*cart::*/set_book(int num, book *b) {

}

/* Function: display_weekly_hours
 * Description: Displays the library's weekly schedule
 * Parameters: none
 * Precondtions: none
 * Postconditions: prints out the schedule of the library for the week
 */
void display_weekly_hours() {
   string week[7]="10-17";
   for(int i=0; i<7; i++){
      if(i==0)
      cout << "Monday: " << week[i] << endl;
      else if(i==1)
	 cout << "Tuesday: " << week[i] << endl;
      else if(i==2)
	 cout << "Wednesday: " << week[i] << endl;
      else if(i==3)
	 cout << "Thursday: " << week[i] << endl;
      else if(i==4)
	 cout << "Friday: " << week[i] << endl;
      else if(i==5)
	 cout << "Saturday: " << week[i] << endl;
      else if(i==6)
	 cout << "Sunday: " << week[i] << endl;
   }
}

/* Function: display_daily_hours
 * Description: Displays the schedule of a single day
 * Parameters: none
 * Preconditions: none
 * Postconditions: prints out the schedule of the library for a single day
 */
void display_daily_hours() {
  int day, i;
  string week[7]="10-17";
  cout << "Enter the number for day that you want to view. 0=Monday, 1=Tuesday, etc: ";
  cin >> day;
      if(day==0)
      cout << "Monday: " << week[i] << endl;
      else if(day==1)
	 cout << "Tuesday: " << week[i] << endl;
      else if(day==2)
	 cout << "Wednesday: " << week[i] << endl;
      else if(day==3)
	 cout << "Thursday: " << week[i] << endl;
      else if(day==4)
	 cout << "Friday: " << week[i] << endl;
      else if(day==5)
	 cout << "Saturday: " << week[i] << endl;
      else if(day==6)
	 cout << "Sunday: " << week[i] << endl;
}

/* Function: add_new_books
 * Description: adds books to the booklist textfile
 * Parameters: none
 * Preconditions: none
 * Postconditions: Book titles are in the booklist textfile
 */
void add_new_books() {
  string title;
  cout << "enter the title of the book that you want to add: " << endl;
  cin >> title;
  getline(cin,title);
  ofstream bookfile;
  bookfile.open("booklist.txt");
  if(bookfile.fail())
     cout << "file failed to open" << endl;

  bookfile << title;
  bookfile.close();
}

/* Function: librarian_options
 * Description: prompts the librarian to tell the program what they would like to do
 * Parameters: none
 * Preconditions: none
 * Postconditions: moves the librarian into the next part of the program
 */
void librarian_options() {
   int opt;
  cout << "Do you want to: (1)change library hours, (2) add new books, (3) remove books, ";
  cout << "(4) view all checked out books, or (5) view a specific book that is checked out?: ";
  cin >> opt;
  if(opt==1) {
   cout << "option 1" << endl; //fill in with a call to changing library hours
  }
  else if(opt==2) {
    cout << "option 2" << endl;
       add_new_books(); //calls add_new_books function
  }
  else if(opt==3) {
    cout << "option 3" << endl; //fill in with a call to remove books
  }
  else if(opt==4) {
    cout << "option 4" << endl; //fill in with a call to view all checked out books
  }
  else if(opt==5) {
    cout << "option 5" << endl; // fill in with a call to view a specific book
  }
}

/* Function: librarian_id
 * Description: checks to make sure the librarian has a valid id number
 * Parameters: none
 * Preconditions: none
 * Postconditions: tell the librarian whether or not their id was valid
 */
void librarian_id() {
   int id_num;
   do{
     cout << "Please enter the librarian id number, which is '1': ";
     cin >> id_num;
     if(id_num==1) {
	cout << "valid id number" << endl;
	librarian_options();
     }
     else
	cout << "invalid id number" << endl;
   }while(id_num!=1);
}

/* Function: patron_id
 * Description: checks to make sure that the patron has a valid id number
 * Parameters: none
 * Preconditions: none
 * Postconditions: tell the patron whether or not their id was valid
 */
void patron_id() {
   int id_num;
   do{
      cout << "Please enter the patron id number, which is '2': ";
      cin >> id_num;
      if(id_num==2) {
	 cout << "valid id number" << endl;
      }
      else
	 cout << "invalid id number" << endl;
   }while(id_num!=2);
}

/* Function: user_id
 * Description: asks the user whehter they want to sign in as a librarian or a patron
 * Parameters: none
 * Preconditions: none
 * Postconditions: moves the user to the next part of the program
 */
void user_id() { 
   int person, id_num;   
   cout << "enter '1' if you're a librarian or '2' if you're a patron: " << endl;
      cin >> person;
      if(person==1) {
	 librarian_id();
      }
      else if(person==2) {
	 patron_id();
      }

}

/* Function: options
 * Description: gives the user the choice of viewing the library schedule, logging in as a patron or librarian, or exiting the program
 * Parameters: none
 * Preconditions: none
 * Postconditions: Moves the user to the next part of the program
 */
void cart::options() {
  int time, option, opt;
  cout << "if you want to see when the library is open, enter '1'. If you want to login, enter '2'. If you want to quit enter '3': ";
  cin >> option;
    if(option==1) {
      cout << "To see the schedule for one day, enter '1'. To see the schedule for the whole week, enter '2': ";
      cin >> opt;
      if(opt==1) {
	 display_daily_hours();
	 options();
      }
      else if(opt==2) {
      cout << "this is the schedule: " << endl;
      display_weekly_hours();
      options();
      }
    }
    else if(option==2) {
      user_id();
      options();
    }
    else if(option==3) {
      
    }
    else {
       cout << "invalid input, please enter 1, 2, or 3" << endl;
       options();
    }
}

/* Function: ~cart
 * Description: acts as the deconstructor for the cart class
 * Parameters: none
 * Preconditions: none
 * Postconditions: dynamically allocated memory is deleted
 */
cart::~cart() { //destructor
  if(books==0)
     books=NULL;
  else
     for(int i=0; i<num_books; i++)
	delete [] books[i].authors;
  delete [] books;
}

/* Function: cart
 * Description: acts as the copy constructor for the cart class
 * Parameters: other
 * Preconditions: other exists
 * Postconditions: cart class is copied to other
 */
cart::cart(const cart &other) { //copy constructor
  num_books=other.num_books;
  if(num_books==0)
     books=NULL;
  else{
     books= new struct book[num_books];
  for(int i=0; i<num_books; i++) {
     books[i].num_authors=other.books[i].num_authors;
     books[i].authors=new string[books[i].num_authors];
     for(int j=0; j<num_books; j++){
	books[i].authors[j]=other.books[i].num_authors;
     }
  }
  }
}


/* Function: operator
 * Description: acts as the assignment overload
 * Parameter: other
 * Precondition: other exists
 * Postconditions: overwrites a class with another class
 */
void cart::operator=(const cart &other) { //assignment overload
   if(num_books==0)
     books=NULL;
   else
   for(int i=0; i<num_books; i++)
     delete [] books[i].authors;
   delete [] books;
  num_books=other.num_books;
  if(num_books==0)
     books=NULL;
  else{
     books= new struct book[num_books];
  for(int i=0; i<num_books; i++) {
     books[i].num_authors=other.books[i].num_authors;
     books[i].authors=new string[books[i].num_authors];
     for(int j=0; j<num_books; j++){
	books[i].authors[j]=other.books[i].num_authors;
     }
  }
  }
}

/* Function: ~library
 * Description: acts as the deconstructor for the library class
 * Parameters: none
 * Preconditions: none
 * Postconditions: dynamically allocated memory is deleted
 */
library::~library() { //destructor
  if(books==0)
     books=NULL;
  else
     for(int i=0; i<num_books; i++)
	delete [] books[i].authors;
  delete [] books;
}

/* Function: library
 * Description: acts as the copy constructor for the library class
 * Parameters: other
 * Preconditions: other exists
 * Postconditions: library class is copied to other
 */
library::library(const library &other) { //copy constructor
  num_books=other.num_books;
  if(num_books==0)
     books=NULL;
  else{
     books= new struct book[num_books];
  for(int i=0; i<num_books; i++) {
     books[i].num_authors=other.books[i].num_authors;
     books[i].authors=new string[books[i].num_authors];
     for(int j=0; j<num_books; j++){
	books[i].authors[j]=other.books[i].num_authors;
     }
  }
  }
}


/* Function: operator
 * Description: acts as the assignment overload
 * Parameter: other
 * Precondition: other exists
 * Postconditions: overwrites a class with another class
 */
void library::operator=(const library &other) { //assignment overload
   if(num_books==0)
     books=NULL;
   else
   for(int i=0; i<num_books; i++)
     delete [] books[i].authors;
   delete [] books;
  num_books=other.num_books;
  if(num_books==0)
     books=NULL;
  else{
     books= new struct book[num_books];
  for(int i=0; i<num_books; i++) {
     books[i].num_authors=other.books[i].num_authors;
     books[i].authors=new string[books[i].num_authors];
     for(int j=0; j<num_books; j++){
	books[i].authors[j]=other.books[i].num_authors;
     }
  }
  }
}
