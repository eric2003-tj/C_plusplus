#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   pair<string,int> x{"Hello"s,150};
   cout << x.first << endl;
   cout << x.second << endl;
}
