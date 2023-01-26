#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdint>
using namespace std;
//#pragma pack(push,1)
typedef struct{
  char a;
  int32_t x;
  int32_t y;
}point;
//#pragma pack(pop)
int main() {
    point p{'a',1,2};
    ofstream of{"file.bin",fstream::binary};
    if(of.is_open()){
        of.write(reinterpret_cast<char*>(&p),sizeof(point));
        of.close();
    }
    ifstream ifile{"file.bin",fstream::binary};
    point p2;
    if(ifile.is_open()){
        ifile.read(reinterpret_cast<char*>(&p2),sizeof(point));
        of.close();
        cout << ifile.gcount() << endl;
        cout << p2.x << " " << p2.y << endl;
    }
}
