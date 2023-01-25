#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
   const int file_size{10};
   char buffer[file_size];
   ifstream ifile{"input.txt"};
   ifile.read(buffer,file_size);
   auto nread = ifile.gcount();
   ifile.close();
   cout << nread << endl;
   cout.write(buffer,file_size);
}
