/* assign3.cpp
 * Author: Peter Nguyen
 * Date: 2/5/2017
 * Description: a program that takes user input and outputs the user's grade in a class
 * Input: positive integers
 * Output: User's grade in a class or section of a class
 */
#include <iostream>
#include <cmath>
using namespace std;

bool loop=true;
double choice;

/* Function: labs()
 * Description: calculates average lab score
 * Parameters: None
 * Pre-Conditions: Positive number
 * Post Conditions: None
 * Return: Average lab grade
 */
double labs() {
   double i,x,y,t,points;
   double sum=0;
	cout << "How many labs?: ";
	cin >> x;
	cout << "Do the total points in the lab vary? (0-no, 1-yes): ";
	cin >> y;
	if(y==0) {
		cout << "How much is each lab worth?: ";
		cin >> t;
		for(i=0; i<x; i++) {
			cout << "Lab score: ";
			cin >> points;
			sum=sum+points;
		}
		cout << "Your average grade is " << sum/(x*t)*100 <<"%" << endl;
	}
	else if(y==1) {
		for(i=0; i<x; i++) {
			cout << "How much is this lab worth?: ";
			cin >> t;
			cout << "What did you score on this lab?: ";
			cin >> points;
			sum=sum+(points/t);
		}
	cout <<"Your average grade is " << (sum/x)*100 << "%" << endl;
	}
	else
	   cout << "That was not a valid input";
	return ((sum/(x*t))*100);
}
/* Function: assignments()
 * Description: Calculates the average assignment grade
 * Parameters: None
 * Pre-Conditions: Positive Number
 * Post Conditions: None
 * Return: Average assignment grade
 */
double assignments() {
   double i,x,y,t,points;
   double sum=0;
	cout << "How many assignments?: ";
	cin >> x;
	cout << "Do the total points in the assignments vary? (0-no, 1-yes): ";
	cin >> y;
	if(y==0) {
		cout << "How much is each assignment worth?: ";
		cin >> t;
		for(i=0; i<x; i++) {
			cout << "Assignment score: ";
			cin >> points;
			sum=sum+points;
		}
		cout << "Your average grade is " << sum/(x*t)*100 <<"%" << endl;
	}
	else if(y==1) {
		for(i=0; i<x; i++) {
			cout << "How much is this assignment worth?: ";
			cin >> t;
			cout << "What did you score on this assignment?: ";
			cin >> points;
			sum=sum+(points/t);
		}
	cout <<"Your average grade is " << (sum/x)*100 << "%" << endl;
	}
	else
	   cout << "That was not a valid input";
	return ((sum/x)*100);
}
/* Function: recitations()
 * Description: Calculates the average quiz recitation, design recitation, critique recitation, and overall recitation grade
 * Parameters: None
 * Pre-Conditions: Positive number
 * Post Conditions: None
 * Return: Average for quizzes, designs, critiques, and overall recitation grade
 */
double recitations() {
	double qw,dw,cw;
	double points_q, points_d, points_c, t_q, t_d, t_c;
	double sum_q=0, sum_d=0, sum_c=0;
	double sum, i, x_q, x_d, x_c, y;
	cout << "Quiz Weight: ";
	cin >> qw;
	cout << "Design Weight: ";
	cin >> dw;
	cout <<"Critique Weight: ";
	cin >> cw;
	if(qw != 0) {
	   double sum=0;
	   double tot_pointsq=0;
	   cout << "How many quizzes?: ";
	   cin >> x_q;
	   cout << "Do the total points in the quizzes vary? (0-no, 1-yes): ";
	   cin >> y;
	   if(y==0) {
	      cout << "How much is each quiz worth?: ";
	      cin >> t_q;
	      for(i=0; i<x_q; i++) {
		 cout << "Quiz score: ";
	      cin >> points_q;
	      tot_pointsq=tot_pointsq+points_q;
	      sum_q=sum+tot_pointsq/x_q;
	   }
	   sum_q=sum_q;
	   cout << "Your Recitation Quiz average is " << sum_q*10 <<"%" << endl;
	 // return (sum/(x*t_q)*100);
	}
	else if(y==1) {
	   for(i=0; i<x_q; i++) {
	      cout << "How much is this quiz worth?: ";
	      cin >> t_q;
	      cout << "What did you score on this quiz?: ";
	      cin >> points_q;
	      sum_q=sum+(points_q/t_q);
	   }
	   sum_q=sum_q;
	   cout <<"Your Recitation Quiz average is " << (sum_q)*10 << "%" << endl;
	 //  return (sum/x);
	}
}
	if(dw !=0) {	
	   double sum=0;
	   double tot_pointsd=0;
	   cout << "How many designs: ";
	   cin >> x_d;
	   cout << "Do the total points in the designs vary? (0-no, 1-yes): ";
	   cin >> y;
	   if(y==0) {
	      cout << "How much is each design worth?: ";
	      cin >> t_d;
	      for(i=0; i<x_d; i++) {
		 cout << "Design score: ";
		 cin >> points_d;
		 tot_pointsd=tot_pointsd+points_d;
		 sum_d=sum+tot_pointsd/x_d;
	      }
	      sum_d=sum_d;
	      cout << "Your Recitation Design grade is " << sum_d*10 <<"%" << endl;
	     // return (sum/(x*t_d)*100);
	   }
	   else if(y==1) {
	      for(i=0; i<x_d; i++) {
		 cout << "How much is this design worth?: ";
		 cin >> t_d;
		 cout << "What did you score on this design?: ";
		 cin >> points_d;
		 sum_d=sum+(points_d/t_d);
	      }
	      sum_d=sum_d;
	      cout <<"Your Recitation design grade is " << (sum_d/*/x_d*/)*10 << "%" << endl;
	    //  return ((sum/x)*100);
	   }
	}
	if(cw !=0) {	
	   double sum=0;
	   double tot_pointsc=0;
	   cout << "How many critiques?: ";
	   cin >> x_c;
	   cout << "Do the total points in the critiques vary? (0-no, 1-yes): ";
	   cin >> y;
	   if(y==0) {
	      cout << "How much is each critique worth?: ";
	      cin >> t_c;
	      for(i=0; i<x_c; i++) {
		 cout << "Critique score: ";
		 cin >> points_c;
		 tot_pointsc=tot_pointsc+points_c;
		 sum_c=sum+tot_pointsc/x_c;
	      }
	      sum_c=sum_c;
	      cout << "Your recitation critique grade is " << sum_c/*/(x_c*t_c)*/*10 <<"%" << endl;
	      //return (sum/(x*t_c));
	   }
	   else if(y==1) {
	      for(i=0; i<x_c; i++) {
		 cout << "How much is this critique worth?: ";
		 cin >> t_c;
		 cout << "What did you score on this critique?: ";
		 cin >> points_c;
		 sum_c=sum+(points_c/t_c);
	      }
	      sum_c=sum_c;
	      cout <<"Your recitation critique grade is " << (sum_c/*/x_c*/)*10 << "%" << endl;
	      //return ((sum/x)*100);
	   }
	}
cout << "Your recitation class average is: " << (((qw*(sum_q) + (dw*(sum_d)) + (cw*(sum_c)))) * 10) << "%" << endl;
return ((qw*(sum_q) + (dw*(sum_d)) + (cw*(sum_c))) * 10);
}
/* Function: tests()
 * Description: Calcuates the average test grade
 * Parameters: None
 * Pre-Conditions: Positive number
 * Post Conditions: None
 * Return: Average test grade
 */
double tests() {
   double i,x,y,t,points;
   double sum=0;
   cout << "How many tests?: ";
   cin >> x;
   cout << "Do the total points in the tests vary? (0-no, 1-yes): ";
   cin >> y;
   if(y==0) {
      cout << "How much is each test worth?: ";
      cin >> t;
      for(i=0; i<x; i++) {
	 cout << "Test score: ";
	 cin >> points;
	 sum=sum+points;
      }
      cout << "Your average test grade is " << sum/(x*t)*100 <<"%" << endl;
   }
   else if(y==1) {
      for(i=0; i<x; i++) {
	 cout << "How much is this test worth?: ";
	 cin >> t;
	 cout << "What did you score on this test?: ";
	 cin >> points;
	 sum=sum+(points/t);
      }
      cout <<"Your average test grade is " << (sum/x)*100 << "%" << endl;
   }
   else
      cout << "That was not a valid input";
   return (sum/x)*100;
}
/* Function: class_grade()
 * Description: Calculates the total class average
 * Parameters: None
 * Pre-Conditions: Positive numbers
 * Post Conditions: None
 * Return: Total class average
 */
double class_grade() {
/*   double a=labs();
   double b=assignments();
   double c=recitations();
   double d=tests(); */
   double a, b, c, d;
   double lab_weight, assign_weight, recitation_weight, test_weight; 
cout << "Enter lab weight: ";
	cin >> lab_weight;
cout << "Enter lab average: ";
	cin >> a;
cout << "Enter assignment weight: ";
	cin >> assign_weight;
cout << "Enter assignment average: ";
	cin >> b;
cout << "Enter recitation weight: ";
	cin >> recitation_weight;
cout << "Enter recitation average: ";
	cin >> c;
cout << "Enter test weight: ";
	cin >> test_weight;
cout << "Enter test average: ";
	cin >> d;
	cout << "Your class average is: " << (lab_weight*a + assign_weight*b + recitation_weight*c + test_weight*d) << "%" << endl;
}
/* Function: main()
 * Description: Contains the rest of the functions for the program
 * Parameters: None
 * Pre-Conditions: A number between and including 0 and 5
 * Post Conditions: None
 * Return: 0
 */
main() {
   do{
      cout << "To calculate averages, enter the number corresponding to the part of class you want calculated. 1) labs, 2) assignments, 3) recitations, 4) tests, 5) the class, or 0) to quit: ";
      cin >> choice;
      if(choice==1) {
	 labs();
      }
      else if(choice==2) {
	 assignments();
      }
      else if(choice==3) {
	 recitations();
      }
      else if(choice==4) {
	 tests();
      }
      else if(choice==5) {
	 class_grade();
      }
      else if(choice==0) {
	 loop=false;
      }
   }while(loop==true);
   return 0;
}
