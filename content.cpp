#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    istream_iterator<string> ii(cin);
    istream_iterator<string> eof;
    vector<string> vs;
    while(ii != eof){
        vs.push_back(*ii);
        ii++;
    }
    for(auto v:vs){
        cout << v << endl;
    }
}
