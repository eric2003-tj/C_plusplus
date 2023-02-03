#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
   vector<int> vec = {1,1,2,3,4,5};
   vector<int> vec2(vec.size());
   auto defunct = unique(begin(vec), end(vec));
	
	cout << "Before calling erase, the vector has " << vec.size() << " elements\n";
	vec.erase(defunct, end(vec));
	
	cout << "After calling erase, the vector has " << vec.size() << " elements\n";
	
	for (auto v : vec)
		cout << v << ", ";
	
}
