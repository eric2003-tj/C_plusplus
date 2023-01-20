#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;
int main(){
   string hello{"Hello World!"};
   for(string::iterator it = hello.begin();it!=hello.end();it++){
      cout << *it << ",";
   }
   cout << endl;
   vector<int> arr = {3,4,5,6,9};
   for(vector<int>::iterator it = arr.begin();it!=arr.end();it++){
      cout << *it << ",";
   }
}
