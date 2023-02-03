#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   vector<int> vec = {1,2,3,4,5};
   vector<int> vec2(vec.size());
   copy_n(cbegin(vec),2,begin(vec2));
   for(auto n: vec2){
      cout << n << endl;
   }
}
