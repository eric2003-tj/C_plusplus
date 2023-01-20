#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;
int main(){
   auto str{"string"s};
   auto num{42};
   cout << str + "sss"s << endl;
   cout << num+5 << endl;
   vector<int> vec = {1,2,6,8,9,2,5};
   for(auto it = vec.begin(); it!= vec.end();it++){
     cout << *it << ' ';
   }
   cout << endl;
   const int& pi = 5;
   auto y = pi;
   cout << y+1 << endl;
   const auto& j = pi;
   j++; // appearing error
}
