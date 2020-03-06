#include <iostream>
#include <string>
using namespace std;

void get_string(string*);
void set_replace_string(string,string*);  
int get_search_replace(string,string&s);
//{
/*   	string s;
	cout <<"Enter your string: ";
	getline(cin,s);
	}

	void set_replace_string(string,string*) {
	string s;
	int i;
	int x=s.length();
	for(int i=0; i<=x; i++) {
	if(s[i]!=' ') {
	s[i]='-';
	}
	}
	}
	*/
int main() {
   string s;
   string p;
   int i;
   get_string(&s);
   set_replace_string(s,&p);
   get_search_replace(s,p);
   cout << p << endl;
   return 0;
}
void get_string(string* s) {
   cout << "Enter any string: ";
   getline(cin,*s);
}
void set_replace_string(string s,string*p) {
   *p=s;
   for(int i=0; s.size()>i; i++) {
      if(s.at(i)!=' ') {
	 (*p).at(i)='-';
      }
   }
}
int get_search_replace(string s,string&p) {
   char a;
   bool loop;
   do{
      for(int i=0; s.size()>i; i++) {
	 cout << "Guess a letter: ";
	 cin >> a;
	 if(a==s.at(i)) {
	    p.at(i)=a;
	    cout << p << endl;
	    loop=true;
	 }
	 else
	    loop=false;
      }
   }while(loop==true);
}
