#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
	cout << boolalpha << (2==3) << endl;
	cout <<left<< setw(15) << "My dog:" << "Brenden";
	cout << endl;
	cout << right;
	cout << setfill('#');
	cout << setw(15) << "My dad" << "Yellow";
}
