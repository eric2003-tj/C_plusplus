#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
    #ifdef float
      double pi {3.1415926535};
      cout << pi << endl;
      double c {299'792'458};
      cout << c << endl;
    #endif // float
    #ifdef scientific notation
      double pi {3.1415926535};
      cout << scientific << pi << endl;
      cout << scientific << uppercase << pi << endl;
    #endif // scientific
    #ifdef fixed
      double c {299'792'458};
      cout << fixed << c << endl;
      double e {1.602e-19};
      cout << fixed << e << endl;
    #endif // fixed
    double pi {3.1415926535};
    cout << pi << endl;
    cout << setprecision(3) << pi << endl;

}
