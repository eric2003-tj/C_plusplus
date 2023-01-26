#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream ifile("input.txt");
    string text;
    vector<int> vec;
    while(getline(ifile,text)){
        istringstream in(text);
        int num;
        while(in >> num){
            vec.push_back(num);
        }
    }
    for(auto n:vec){
        cout << n << endl;
    }
}
