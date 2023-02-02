#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   string str{"Hello world!"};
   string vowel{"aeiou"};
   cout << str.find_first_of(vowel) << endl;
   auto pos = adjacent_find(cbegin(str),cend(str));
   cout << *pos << endl;
   vector<int> vec = {1,1,2,2,3,3,3,3};
   auto pos2 = search_n(cbegin(vec),cend(vec),4,3);
   cout << *pos2 << endl;
   string temp{"wor"};
   auto pos3 = search(cbegin(str),cend(str),cbegin(temp),cend(temp));
   cout << *pos3 << endl;
}
