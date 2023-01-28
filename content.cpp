#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdint>
using namespace std;
class Test {
    public:
        int i;
        string str;
    // Class interface function declarations
    // Compiler-generated copy constructor
    // Initializes "this" by copying the argument's i member
    // and calling std::string's copy constructor for y
    // Test(const Test& other) : i(other.i), y(other.y) {}
    Test(int x,string new_str){
       i = x;
       str = new_str;
    }
    Test(const Test& other){
       i = other.i;
       str = other.str;
    }
};

int main() {
    Test nee{5,"hello"};
    Test trial{nee};
    cout << trial.i << endl;
    cout << trial.str << endl;
}
