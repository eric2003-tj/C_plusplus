#include <string>
#include <iostream>
#include "Url.h"
using namespace std;
void Url::display(){
   cout << protocol <<"://"<< resource << '\n';
   return ;
}
