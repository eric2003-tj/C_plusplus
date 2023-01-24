#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main(){
   #ifdef to_string()
     string pi{to_string(3.1415926)};
     cout << pi << endl;
   #endif // to_string
  #ifdef stoi()
     size_t n; // 定義物件的大小
     auto i = stoi("12345",&n);
     cout << n << endl;
     string str{"42.56"};
     cout << stoi(str) << endl;
   #endif // stoi
   #ifdef error_handling
     size_t n_proceed;
     string str{"1235  666666"};
     auto i = stoi(str,&n_proceed);
     if(n_proceed < str.size()){
        cout << "The first non-numeric " << n_proceed << endl;
     }
   #endif // error_handling
   #ifdef Base Conversion
     int a = stoi("2a",nullptr,16);
     cout << a << endl;
   #endif // Base
}
