#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main(){
   string s1{"hello"};
   string s2{" world"};
   s1 += s2;
   cout << s1 << endl;
   cout << (s1 > s2) << endl;
   const char* cstr = s1.c_str();
   cout << cstr << endl;
   string str {"Hello world"};
   str[1] = 'a';
   string st1 = str.substr(6);
   string st2 = str.substr(6,2);
   cout << "st1 is :" << st1 << endl;
   cout << "st2 is :" << st2 << endl;
   string triplex(3, 'x');
   cout << triplex << endl;
   string temp(str,1,5);
   cout << temp << endl;
   return 0;
}
