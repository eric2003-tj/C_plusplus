#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
  ifstream ifile;
  ifile.open("input.txt");
  int x;
  while(ifile >> x){
    cout << x << ",";
  }
  ifile.close();
}
