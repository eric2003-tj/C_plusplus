#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
using namespace std;
bool equal_strings(const string& lhs, const string& rhs) {
    if (lhs.size() != rhs.size())
      return false;
    auto lit=lhs.cbegin();
    auto rit = rhs.cbegin();
    while (lit != lhs.cend() && rit != rhs.cend()) {
        if (toupper(*lit) != toupper(*rit))
        return false;
        ++lit;
        ++rit;
    }
    return true;
}
int main(){
   string str{"To be, or not to be, that is the question:"};
   for(auto &it:str){
     if(isupper(it)){
        cout << it << " is an uppercase ch\n";
     }else if(islower(it)){
        cout << it << " is a lowercase ch\n";
     }else if(isdigit(it)){
        cout << it << " is a digit\n";
     }else if(isspace(it)){
        cout << R"(' ')" << " is a digit\n";
     }else if(ispunct(it)){
        cout << it << " is a punctuation\n";
     }
   }
}
