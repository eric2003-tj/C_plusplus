#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main(){
   #ifdef data()
      string str{"20202"};
      cout << str.data() << endl;
   #endif // data
   #ifdef swap
      string str1{"Hello"};
      string str2{"Goodbye"};
      str1.swap(str2);
      cout << str1 << endl;
      swap(str1,str2);
      cout << str1 << endl;
   #endif // swap
}
