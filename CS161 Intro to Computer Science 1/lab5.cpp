#include <iostream>
#include <string>
using namespace std;
void get_sentence(string&s){
cout << "Enter your string: ";
getline(cin,s);
}

int main(){
string sentence;
string s;
get_sentence(s);
cout << s << endl;

return 0;
}
