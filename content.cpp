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
     for(int i=0;i<666666;i++){
        cout << i << '\n' << flush;
        ofile << i << '\n' << flush; // equivalent to endl func
        if(i==10000){
            terminate();
        }
     }
     ofile.close();
   }
}
