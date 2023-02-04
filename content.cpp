#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   vector<int> vec = {1,1,2,3,4,5};
   auto func = [](int n){return (n%2==1);};
   stable_partition(begin(vec),end(vec),func);
   for(auto n:vec){
      cout << n << endl;
   }
}
