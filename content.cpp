#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   int y = 1;
   auto func = [y = y+1](int x) { return x + y; };
    cout << func(5) << endl;
    cout << y<< endl;
}
