#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;
int main(){
   // New forms of begin() and end()
   vector<int> vec = {1,2,3,4,5};
   for(auto it = vec.begin();it != vec.end();it++){
      cout << *it << ' ';
   }
   cout << endl;
   for(auto it = vec.rbegin();it != vec.rend();it++){
      cout << *it << ' ';
   }
   cout << endl;
   for(auto it = vec.cbegin();it != vec.cend();it++){
      cout << *it << ' ';
   }
   cout << endl;
   for(auto it = vec.crbegin();it != vec.crend();it++){
      cout << *it << ' ';
   }
   cout << endl;
   // Global begin() and end()
   int arr[5] = {1,2,3,4,5};
   for(auto it = begin(arr);it!=end(arr);it++){
     cout << *it << ' ';
   }
   cout << endl;
   // Range for loops
   for(auto it:vec){
     cout << it << ' ';
   }
   cout << endl;
   for(auto &it:vec){
     it += 2;
     cout << it << ' ';
   }
   cout << endl;
   // When to use range for loops
   for(auto it = vec.begin();it != vec.end();it++){
      if(*it % 2 == 1){
         vec.erase(it);
         it--;
      }
   }
   for(auto it = vec.begin();it != vec.end();it++){
      cout << *it << ' ';
   }
}
