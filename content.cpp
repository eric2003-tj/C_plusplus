#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;
int main(){
   // Initializer in if Statement
   vector<int> vec = {1,2,3,4,5};
   if(auto v = vec.begin();*v!=2){
      cout << "The first is not 2"<<endl;
   }
   // Initializer in Switch Statement
   vector<string> vecstr = {"abcde","fghjk"};
   for(auto v = vecstr.begin();v!=vecstr.end();v++){
      switch(auto x = (*v).begin();*x){
    case 'a':
        cout<<"hello"<<endl;
        break;
    default:
        cout << "error"<<endl;
        break;

      }
   }
   //fallthrough
   int a{2};
   switch(a){
 case 1:
    [[fallthrough]];
 case 2:
    [[fallthrough]];
 case 15:
    cout<<15<<endl;
    break;
 default:
    cout << "mmm" << endl;
    break;
   }

}
