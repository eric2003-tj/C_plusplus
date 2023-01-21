#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main(){
   string str{"Hello world"};
   if(str.find('o') != string::npos){
      cout << str.find('o') << endl;
   }
   if(str.find("or") != string::npos){
      cout << str.find("or") << endl;
   }
   if(str.find('O') != string::npos){
      cout << str.find('O') << endl;
   }
   if(str.rfind('o') != string::npos){
      cout << str.rfind('o') << endl;
   }
   if(str.rfind("or") != string::npos){
      cout << str.rfind("or") << endl;
   }
   if(str.rfind('O') != string::npos){
      cout << str.rfind('O') << endl;
   }
   string vowels {"aeiou"};
   cout << str.find_first_of(vowels) << endl;
   cout << str.find_last_of(vowels) << endl;
   cout << str.find_first_not_of(vowels) << endl;
   cout << str.find_last_not_of(vowels) << endl;
}
