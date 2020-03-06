#include <iostream>
#include <fstream>

using namespace std;

void create_header(ifstream &input, ofstream &output) {
  char title[256];

  output << "<head>" << endl;
  
  input.getline(title, 256);

  output << "<title>" << title << "</title>" << endl;
  output << "</head>" << endl;

}

void create_html(ifstream &input) {
  

   
  ofstream output;
  output.open("index.html");

  ouput << "<html>" << endl;
  create_header(input, output);

  output << "</html>" << endl;

}

int main() {

}

  ifstream input;
  input.open("input.txt");

  if(input.fail()){
  	cout << "The file failed to open!" << endl;
	return 0;
  }

  create_html(input);

   return 0;
