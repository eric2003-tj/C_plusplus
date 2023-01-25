#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
  int x;
  cin >> x;
  if(cin.good()){
    cout << "You successfully entered an integer\n";
  }else if(cin.fail() || cin.bad()){
    cout << "Please reenter an integer\n";
  }
}
