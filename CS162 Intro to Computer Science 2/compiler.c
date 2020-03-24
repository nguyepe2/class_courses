/* Program Filename: compiler.c
 * Author: Peter Nguyen
 * Date: 6/11/17
 * Description: checks to see if brackets, braces, and parentheses are balanced
 * Input: any number of brackets, braces and parentheses
 * Output: A message saying whether or not the input was balanced
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
   struct list l;
   struct node n;
   char str[200];
   struct node *t = l.head;
   int i=0;
   init(&l);
   printf("%s \n","Enter a combination of brackets, braces, and parentheses: ");
   scanf("%s", str);

   while(i<strlen(str)) { //moves input into the list
      if(str[i]=='{')
	 push_back(&l, 0);
      else if(str[i]=='}')
	 push_back(&l, 1);
      else if(str[i]=='[')
	 push_back(&l, 2);
      else if(str[i]==']')
	 push_back(&l, 3);
      else if(str[i]=='(')
	 push_back(&l, 4);
      else if(str[i]==')')
	 push_back(&l, 5);
      i++;
   }


   if(size(l)==1) {  //deletes memory if only one thing in list
      printf("%s \n", "input rejected");
      free(l.tail);
      return 0; 
   }
   else if(front(l)==1 || front(l)==3 || front(l)==5) { //if bad starting value, deletes memory
      printf("%s \n", "input rejected");
      delete(&l);
      return 0; 
   }
   else if(size(l) % 2!=0) { //if uneven amount of values in list, deletes memory
      printf("%s \n", "input rejected");
      delete(&l);
      return 0;
   } 
   do{
      if("%i", back(l)!=("%i",front(l)+1)) { //if front and back of list aren't correct, deletes memory
	 printf("%s \n","input rejected");
	 delete(&l);
	 return 0;
      }
      else {
	 printf("%s \n", "input accepted"); //if front and back are correct, deletes memory
	 if(size(l)==2) {
	    free(l.head);
	    free(l.tail);
	    return 0;
	 }
	 remove_front(&l);
	 pop_back(&l);
      } 
   }while(size(l)!=0);
}
