#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class is_smaller{
    public:
      bool operator()(int lhs,int rhs){
        return(rhs < lhs);
      }
};
int main(){
    vector<int> vec = {4,9,6,3,1,2};
    sort(begin(vec),end(vec),[](int lhs,int rhs){return (rhs<lhs);});
    for(auto n:vec){
        cout << n << ",";
    }
}