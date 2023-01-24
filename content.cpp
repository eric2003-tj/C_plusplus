#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
using namespace std;
void convert(string& str){
    for(auto it=str.begin();it!=str.end();it++){
        if(ispunct(*it)){
            *it = '!';
        }
    }
}
int main(){
   //assignment 4
   string str{"To be, or not to be, that is the question:"};
   convert(str);
   cout << str;
}
