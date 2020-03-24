#include <iostream>
#include <stdlib.h>
using namespace std;

struct mult_div_values{
   int mult;
   float div;
};


bool is_valid_dimensions(char **argv, int* rows, int* cols);
mult_div_values** create_table(int rows, int cols);
void set_mult_values(mult_div_values **table, int rows, int cols);

bool is_valid_dimensions(char **argv, int* rows, int* cols) {
   *rows=atoi(argv[1]);
   *cols=atoi(argv[2]);
   do{
      if(*rows < 1) {
	 cout << "invalid amount of rows, please enter an integer greater than 0 " << endl;
	 cin >> argv[1];
      }
   }while(atoi(argv[1]) < 1);

   do{
      if(*cols < 1) {
	 cout << "invalid amount of columns, please enter an integer greater than 0" << endl;
	 cin >> argv[2];
      }
   }while(atoi(argv[2]) < 1);
   *rows=atoi(argv[1]);
   *cols=atoi(argv[2]);
}

mult_div_values** create_table(int rows, int cols) {
   mult_div_values** table = new mult_div_values*[rows];
   for(int i=0; i<rows; i++) {
      table[i]=new mult_div_values[cols];
      return table;
   }
   /*for(int i=0; i<rows; i++)
     for(int j=0; j<cols; j++)
     cout << *array[i][j];
     cout << rows << endl;
     cout << cols;
     */
}

void set_mult_values(mult_div_values **table, int rows, int cols) {
   cout << endl;
   int i;
   int j;
   for(i=0; i<rows; i++) {
      for(j=0; j<cols; j++) {
	 table[i][j].mult=(i+1)*(j+1);
	 cout << table[i][j].mult << "\t";
      }
      cout << endl;
   }
}

int main(int argc, char **argv) {
   int rows=atoi(argv[1]);
   int cols=atoi(argv[2]);
   //int rows, cols;
   if(argc !=3){
      cout << "Incorrect number of args. There must be 3 arguments. " << endl;
      return 0;
   }
   is_valid_dimensions(argv, &rows, &cols);
   mult_div_values** table = create_table(rows, cols);
   set_mult_values(table, rows, cols);


   //  int rows=atoi(argv[1]);
   //  int cols=atoi(argv[2]);
}

/*bool is_valid_dimensions(char **argv) {

  int rows=atoi(argv[1]);
  int cols=atoi(argv[2]);


  }
  */
