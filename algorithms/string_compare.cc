#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>
using namespace std;
bool compare(const string& lhs, const string& rhs){
    if(lhs.size() != rhs.size()){
        return false;
    }
    auto lbegin = cbegin(lhs);
    auto rbegin = cbegin(rhs);
    while(lbegin != cend(lhs)){
        if(toupper(*lbegin) != toupper(*rbegin)){
            return false;
        }else{
            lbegin++;
            rbegin++;
        }
    }
    return true;
}
int main(){
    cout << boolalpha << compare("apple","Apple") << endl;
    cout << boolalpha << compare("44444","55555");
}