#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
   //vector
   vector<int> vec = {4,2,3,4,1};
   for(int i=0;i<vec.size();i++){
      cout << "vec[" << i <<"] :" << vec[i] <<endl;
   }
   vec[2] = 6;
   for(int i=0;i<vec.size();i++){
      cout << "vec[" << i <<"] :" << vec[i] <<endl;
   }
   vec.push_back(7);
   for(int i=0;i<vec.size();i++){
      cout << "vec[" << i <<"] :" << vec[i] <<endl;
   }
   //string
   string hello{"Hello"};
   cout << hello << '\n';
   hello[3] = 'b';
   cout << hello << '\n';

}
