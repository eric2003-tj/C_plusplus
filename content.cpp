#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;
void print(char *str){
   cout << str << endl;
   return ;
}
int main(){
   // casting
   // static-cast dynamic-cast reinterpret-cast const-cast
   int a = 65;
   cout << static_cast<char>(a) << endl;
   const char* url = R"(https://www.udemy.com/course/learn-intermediate-modern-c/learn/lecture/29453340#questions)";
   print(const_cast<char*>(url));

}
