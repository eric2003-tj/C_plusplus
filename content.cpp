#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
using namespace std::literals;
// Writing a template
template<class T>
T Max(const T& a,const T& b){
  if(a > b){
     return a;
  }
  return b;
}
template<class T>
class Tmems{
  private:
      T data;
  public:
      Tmems(T new_data){
        data = new_data;
      }
      void get_data(){
        cout << data << endl;
      }
};
namespace abc{
  vector<int> vec{1,2,3};
  string str{"abcd"};
  class Yumn{
private:
    int x;
public:
    Yumn(int new_x){
      x = new_x;
    }
    void get_data(){
      cout << x << endl;
    }
  };
}
namespace def{
  vector<int> vec{1,2,3};
  string str{"abcd"};
  class Yumn{
private:
    int x;
public:
    Yumn(int new_x){
      x = new_x;
    }
    void get_data(){
      cout << x << endl;
    }
  };
}
using def::Yumn;
int main(){
   cout << Max(4.3,2.0) << endl;
   /*
     double Max(const double &a ,const double &b){
        if(a > b){
     return a;
          }
          return b;
     }
   */
   Tmems<string> item1{"Hello"};
   item1.get_data();
   vector vec = {1,2,3}; // for C++ 17
   for(auto it:vec){
      cout << it << ",";
   }
   cout << abc::str << endl;
   Yumn ob{6};
   ob.get_data();

}
