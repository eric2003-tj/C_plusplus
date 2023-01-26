#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    ostream_iterator<int> oi(cout,"\n");
    for(int i=0;i<10;i++){
        *oi = i;
        oi++;
    }
}
