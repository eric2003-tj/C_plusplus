#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
class Test{
   public:
       bool operator()(int n){
          return (n%3==0);
       }
};
int main(){
    Test t;
    if(t(3)){
        cout << "ff";
    }
}
