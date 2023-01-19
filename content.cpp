#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
   // two-dimensional
   int di_array[4][2] = {{1,2},{3,4},{5,6},{7,8}};
   for(int i = 0;i<4;i++){
     for(int j=0;j<2;j++){
        cout << "array[" << i << "][" << j << "]:" << di_array[i][j] << " ";
     }
     cout << endl;
   }
   //flatten
   int arr[8] = {1,2,3,4,5,6,7,8};
   for(int i=0;i<4;i++){
     for(int j=0;j<2;j++){
        cout << "array[" << i << "][" << j << "]:" << arr[4*i+j] << " ";
     }
     cout << endl;
   }
}
