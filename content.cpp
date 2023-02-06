#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <array>
#include <forward_list>
using namespace std;

int main(){
  forward_list<int> lists{4,3,1};
  auto second = lists.begin();
  advance(second,1);
  lists.insert_after(second,2);
  for(auto v:lists){
   cout << v << endl;
  }
}
