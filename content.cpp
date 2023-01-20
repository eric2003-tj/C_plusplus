#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;
int main(){
   // Iterator Ranges and Arithmetic
   string str{"12345"};
   auto start = str.begin();
   cout << *next(start) << endl;
   auto last = str.end()-1;
   cout << *last << endl;
   auto mid = start+ distance(start,last)/2;
   cout << *mid;
}
