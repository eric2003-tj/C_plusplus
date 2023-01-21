#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
void func(int a,int b){
  cout << a << " + " << b << " = " << a+b;
  return ;
}
using pfunc = void(*)(int,int);
pfunc other_func(){
   return &func;
}
int main(){
   int a{5};
   int b{3};
   auto fun_ptr = &func;
   (*fun_ptr)(a,b);
   cout << endl;
   (*other_func())(a,b);
}
