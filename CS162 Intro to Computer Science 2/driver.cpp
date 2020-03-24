/* Program: driver.cpp
 * Author: Peter Nguyen
 * Date: 4/30/2017
 * Description: A program that mimics a library by allowing users to view the library schedule, check in or out books or add/remove books
 * Input: A number to tell the program which option you want to choose
 * Output: The option that you wanted to do
 */
#include "cart.h"
#include "structs.h"
#include <iostream>
using namespace std;

int main() {
  cart c;
  c.set_num_books(5);
  int x=c.get_num_books();
  cout << x << endl;
  c.options();
}
