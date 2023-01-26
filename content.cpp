#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdint>
using namespace std;
class refrigerator {
    // Data members
    int temperature{2};
    bool door_open;
    bool power_on;
public:
    refrigerator(int new_temp,bool dr,bool po){
       temperature = new_temp;
       door_open = dr;
       power_on = po;
    }
    void print(){
       cout << temperature << endl;
       cout << boolalpha << door_open << endl;
       cout << power_on << endl;
    }
};

int main() {
    refrigerator refr(5,true,false);
    refr.print();
}
