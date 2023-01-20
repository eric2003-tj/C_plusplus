#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;

int main(){
   // String literals
   cout << "Hello"s + " world"s << endl;
   // Raw string
   string url = R"(<a href="file">C:\Program Files\</a>\n)";
   cout << url << endl;
   string url2 = R"x(<a href="file">C:\Program Files (x86)\</a>\n)x";
   cout << url2 << endl;
}
