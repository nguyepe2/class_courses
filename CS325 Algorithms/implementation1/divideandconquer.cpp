#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int x[100000];
int y[100000];
string str;

class points {
  public:
    int xval;
    int yval;

};

int recursion(int x[], int y[], int num) {
  //split the array
  int half;
  half=num/2;
  sort(y, y+num);

  if(half==1 || half==2) {
    return x[half];
  }
  else {
    return recursion(x, y, half);
  }


}

int main() {
   ifstream infile;
   int num=0;

   points store[100000];
   vector<points> storage;

   infile.open("example.input");

   while(getline(infile, str)) {
     infile >> x[num];
     infile >> y[num];

     points point;
     point.xval=x[num];
     point.yval=y[num];
     //infile >> point.xval;
     //infile >> point.yval;

     //store[num]=point;
     //cout << store[num].xval << ' ' << store[num].yval << '\n';

     storage.push_back(point);

     //cout << '\n';

     //cout << x[num] << '\n';

     num++;

   }

   int i;

   for(auto int i=storage.begin(); i != storage.end(); ++i) {
     cout << *i << endl;
   }

   //sort the x array
     //swap(store[0], store[1]);

     //cout << "previous value of array[1]: " << store[0].xval << ' ' << store[0].yval << '\n';
     //cout << "previous value of array[0]: " << store[1].xval << ' ' << store[1].yval << '\n';

   //sort(x, x+num);
   //sort(store, store+num);

   recursion(x, y, num);

   infile.close();


  // return 0;

}
