#include <iostream>
#include <cstring>
using namespace std;

int main() {

/*char str[20];

cout << "Enter 19 chars: ";
cin >> str;
cout << "String beginning address: " << (void *)str << endl;
cout << "String contents: " << str << endl;
*/

/*char s;
char *str=new char[1];
char *temp;

str[0]='\0';
cout << "Length: " << strlen(str) << endl;
cin.get(s);
while(s!='\n') {
	temp=str;
	str=new char[strlen(temp)+2];
	strcpy(str,temp);
	str[strlen(temp)]=s;
	str[strlen(temp)+1]='\0';
	delete [] temp;
	cin.get(s);
	}
*/
/*char s;
char *str=new char[1];
char *temp;
int max_chars;
*/
char length;
cout << "Enter the length of the string: ";
cin >> length;

char *array=new char[length];
char *str;
cin.getline(array, length+1);
cout << "Enter your string: ";
cin >> str;
cout << *array << endl;
return 0;
}

