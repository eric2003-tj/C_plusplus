#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
   ifstream ifile{"text.txt"};
   if(ifile){
      string text{""};
      while(getline(ifile,text)){
        cout << text << " ";
      }
   }
}
