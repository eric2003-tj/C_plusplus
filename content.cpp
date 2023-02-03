#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   vector<int> vec = {1,2,3,4,5};
   vector<int> vec2(vec.size());
   copy_if(cbegin(vec),cend(vec),begin(vec2),[](int n){return (n%2 == 0);});
   for(auto n: vec2){
      cout << n << endl;
   }
}
