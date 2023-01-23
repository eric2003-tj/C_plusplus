#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
int main(){
   //append()
   string hello{"hello"};
   hello.append(" world"); //hello world
   string hello2 {"Hello"};
   hello2.append("wow!!!!", 3, 2); //Hello!!
   cout << hello << endl;
   cout << hello2 << endl;
   //insert()
   #ifdef insert()
   string str{ "for" };
   str.insert(2, "lde"); //folder
   string str2{ "care" };
   string str3{ "omp" };
   str2.insert(1, str3); // compare
   cout << str << endl;
   cout << str2 << endl;
   #endif // insert
   //insert() - conti
   #ifdef insert()-conti
   string str { "xx" };
   string str2{ "trombone" };
   str.insert(1, str2, 4, 2); //xbox
   string str3("cash");
   str3.insert(1, 3, 'r'); //crrrash
   auto opos = hello.find('o');
   hello.insert(opos, 2, 'o'); //hellooo
   cout << str << endl;
   cout << str3 << endl;
   cout << hello << endl;
   #endif // insert
   #ifdef iterator
   string str{ "word" };
   auto last = str.end() - 1;
   str.insert(last, 'l'); //world
   string str2{ "ski" };
   auto last2 = str2.end();
   str2.insert(last2, 2, 'l'); //skill
   cout << str << endl;
   cout << str2 << endl;
   #endif // iterator

}
