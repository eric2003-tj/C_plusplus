#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
class Test{
   public:
       Test() = default;
       Test(const Test&) = delete;                    // Deleted copy constructor
       Test& operator =(const Test&) = delete;        // Deleted assignment operator
};
int main(){
    Test t1, t2;                                   // Use defaulted constructor
	Test t3(t1);                                   // Error: use of deleted function
	t2 = t1;
}
