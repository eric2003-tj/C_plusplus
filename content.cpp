#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
   ifstream ifile{"text.txt"};
   while(ifile){
      string text{""};
      while(ifile >> text){
        cout << text << " ";
      }
   }
}
