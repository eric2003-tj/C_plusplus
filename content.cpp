#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
    int x{42}, y{99}, z{0};
    auto lam = [=,&z]() mutable { ++x; ++y; z = x + y; };
    lam();
    cout << x << " " << y << " " << z << endl;
    lam();
    cout << x << " " << y << " " << z;
}
