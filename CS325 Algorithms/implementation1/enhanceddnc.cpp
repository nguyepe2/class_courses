#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <ctime>
#include <time.h>

using namespace std;

int start=clock() ;

struct Point{
   int x,y;
};

vector<Point> readIn(string filename){
   vector<Point> points;
   ifstream myfile(filename.c_str());

   if (myfile.is_open())
   {
      while(1) // reads file to end of *file*, not line
      {
	 Point point;
	 myfile >> point.x; // read first column number
	 myfile >> point.y; // read second column number
	 if(myfile.eof())
	    break;

	 points.push_back(point);
      }
   }
   myfile.close();
   return points;
}

void writeOut(){


}

bool pointComparerX(Point a, Point b)
{
   return a.x < b.x;
}

bool pointComparer(Point a, Point b)
{
   if (a.x != b.x)
      return a.x < b.x;

   else
      return a.y < b.y;
}

double dist(Point P1, Point P2){
   float d =pow(pow((P1.x - P2.x),2) + pow((P1.y - P2.y),2),.5);
   int min=INT_MAX; //initialize min to maximum signed int
   /*if(d<min) {
     min=d;
   }*/
   //call divCon again, adding 1 to begin
   //cout << UINT_MAX << endl;
   //cout << "this is the distance: " << min << endl;
   //cout << "point x1: " << P1.x << " " << "y1: " << P1.y << endl;
   //cout << "point x2: " << P2.x << " " << "y2: " << P2.y << endl;
   return d;
}

void sortX(vector<Point> &points){
   sort(points.begin(),points.end(), pointComparer);
}


void display(vector<Point> points, int n){
   for(int i =0;i<n;i++){
      cout << points[i].x << "  " << points[i].y << endl;
   }
   cout << endl;
   cout << endl;
}

int medianInd(vector<Point> &points){
   return points.size()/2;
}

double min(double d1, double d2){
   if(d1 == -1 && d1 == -1){
      return 0;
   }
   else if(d1 == -1){
      return d2;
   }
   else{
      return d1;
   }
   if(d1 == d2){
      return d1;
   }
   else if(d1 > d2){
      return d2;
   }
   else{
      return d1;
   }
}

int returnIndex(vector<Point> &points, double range, int limitType){
   int index;

   return index;
}

double divCon(vector<Point> &points, int begin, int end){
   int d1, d2, middle, range;
  //cout << begin << endl;
   if(begin > 2){ //points.size
      //cout << "hello" << begin << endl;
      //cout << "greater than 2" << endl;
      d1 = divCon(points, points.size()/2, points.size()); //(points, points.size()/2, points.size())
      d2 = divCon(points, 0, points.size()/2); //(points, 0, points.size()/2)
   }
   else{
      if(points.size() == 1){ //points.size
	 return -1;
      }
      else{
      //  cout << "hello end " << begin << endl;

	 return dist(points[0],points[1]);
      }
   }

   //Calculate the median
   middle = medianInd(points);
   range = (points[medianInd(points)].x + min(d1,d2)) - (points[medianInd(points)].x - min(d1,d2));

   //find what X valves are within delta
   // find the index?
   // or just compare all points?
   //Sort by Y
   // determine distance between points
   // all things on the same side cannot be evaluated
   //

}


int main(int argc, char* argv[]){
  if(argc!=2) {
    cout << "program needs two arguments, the name of the executable and the file to read" << endl;
    exit(1);
  }

   float distance;
   vector<Point> points;
   vector<Point> store;
   float min=FLT_MAX; //initialize min to maximum signed int
   ofstream myfile;


   points = readIn(argv[1]);
   //display(points, points.size());
   sortX(points);
   //display(points, points.size());

   for(int i=0; i<points.size(); i++) {
    distance = dist(points[i], points[i+1]);

    if(distance < min) {
      min=distance;
      store.clear();
      store.push_back(points[i]);
      store.push_back(points[i+1]);
    }
    else if(distance==min) {
      store.push_back(points[i]);
      store.push_back(points[i+1]);
    }

   }

   myfile.open("output_enhanceddnc.txt");

   myfile << min << endl;
   for(int i; i < store.size(); i++) {
     myfile << "(" << store[i].x << "," << store[i].y << ")";
     if(i % 2==0) {
       myfile << ", ";
     }
     else {
       myfile << endl;
     }
   }

   myfile.close();

   int stop=clock();
   //cout << "time: " << (stop-start)/double(CLOCKS_PER_SEC)*1000 << endl;
   //display(store, store.size());
   //cout << FLT_MAX << endl;
   //divCon(points, 0, points.size());
   //cout << UINT_MAX << endl;

   return 0;
}
