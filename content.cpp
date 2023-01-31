#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
class Test{
   int i;
   public:
       Test(int d){
           i = d;
       }
       explicit operator int() const{return i;}
};
int main(){
   Test ob{7};
   //cout << ob << endl;
   cout << static_cast<int>(ob) << endl;
}
