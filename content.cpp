#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
   ofstream ofile{"text_out.txt"};
   if(ofile){
     vector<string> vec = {"dddd","xxxxx","apple"};
     for(auto v:vec){
        ofile << v << ",";
     }
     ofile.close();
   }
}
