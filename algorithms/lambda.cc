#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

class is_shorter{
  public:
    bool operator()(const string& str){
        return(str.size() < 5);
    }
};
int main(){
   is_shorter dd;
   cout << boolalpha << dd("ssssssssss");
}