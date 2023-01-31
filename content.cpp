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
       operator int() const{return i;}
};
int main(){
   Test ob{7};
   cout << ob << endl;
}
