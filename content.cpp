#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   vector<int> vec = {1,2,3,4,5};
   vector<int> vec2(vec.size());
   replace_if(begin(vec),end(vec),[](int n){return (n%2==0);},2);
   for(auto n: vec){
      cout << n << endl;
   }
}
