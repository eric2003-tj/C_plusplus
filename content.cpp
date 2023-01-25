#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
   ofstream ofile;
   ofile.open("input.txt",fstream::app);
   ofile << "\n123456789";
   ofile.close();

}
