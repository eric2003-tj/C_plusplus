#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
    vector<string> vec = {"assd","bhhsdf","dfdfdd"};
    int max{5};
    int idx{-1};
    auto res = find_if(cbegin(vec),cend(vec),[max,&idx](const string& str){++idx; return str.size() > max;});
    cout << idx << endl;
}
