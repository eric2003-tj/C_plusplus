#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    ostringstream os;
    cout << "Please enter an word:" << '\n';
    string text;
    cin >> text;
    os << text;
    cout << "please enter another word: " << endl;
    cin >> text;
    os << text;
    cout << os.str() << endl;
}
