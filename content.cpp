#include <iostream>
using namespace std;

int main(){
   // exercise of pointers
   int *p1 = new int{36};
   cout << "p1 is " << p1 <<'\n';
   cout << "*p1 is " << *p1 <<'\n';
   // implementing arrays
   int *array1 = new int[20];
   for(int i = 0;i< 20;i++){
     array1[i] = i;
     cout << "array1[" << i << "] :" << array1[i] <<'\n';
   }
   delete[] array1;
}
