#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main(){
   #ifdef erase()
      string str{"hello"};
      str.erase(1,2); // indexes
      cout << str << endl;
      str.assign("hello");
      str.erase(str.begin(),str.begin()+2);
      cout << str << endl;
   #endif // erase
   #ifdef replace()
      string str{"hello"};
      str.replace(1,3,"lllllll"); // replace three elements
      cout << str << endl;
      str.assign("hello");
      str.replace(str.begin()+1,str.end()-2,"llllllll");
      cout << str << endl;
   #endif // replace

}
