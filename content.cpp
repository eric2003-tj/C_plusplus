#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   vector<int> vec = {1,2,3,4,5};
   vector<int> vec2(vec.size());
   auto defunct = remove(begin(vec),end(vec),1);
   vec.erase(defunct,end(vec));
   for(auto n: vec){
      cout << n << endl;
   }
}
