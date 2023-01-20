#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main(){
   // integers
   // four types: char int long long long
   cout << "char :" << sizeof(char) << endl;
   cout << "int :" << sizeof(int) << endl;
   cout << "long :" << sizeof(long) << endl;
   cout << "long long :" << sizeof(long long) << endl;
   // fixed-width
   cout << "int8_t :" << sizeof(int8_t) << endl;
   cout << "int16_t :" << sizeof(int16_t) << endl;
   cout << "int32_t :" << sizeof(int32_t) << endl;
   cout << "int64_t :" << sizeof(int64_t) << endl;
   cout << "uint8_t :" << sizeof(uint8_t) << endl;
   cout << "uint16_t :" << sizeof(uint16_t) << endl;
   cout << "uint32_t :" << sizeof(uint32_t) << endl;
   cout << "uint64_t :" << sizeof(uint64_t) << endl;
   // numeric literals
   int bi = 0b110;
   int oc = 077;
   int hex = 0x95;
   cout << "binary:" << bi << endl;
   cout << "oc:" << oc << endl;
   cout << "hex:"<< hex << endl;
   // Digit Separator in Numeric Literals
   double pi = 3.1'415'9;
   cout << "pi:" << pi << endl;

}
