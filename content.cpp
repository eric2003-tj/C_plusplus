#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1{"hello world"s};
	for(auto i =s1.begin();i!=s1.end();i++){
        cout << *i << endl;
	}
}
