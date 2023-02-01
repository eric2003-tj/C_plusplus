#include <string>
using namespace std;
class Url{
  private:
      string protocol;
      string resource;
  public:
      Url(string new_protocol,string new_resource){
         protocol = new_protocol;
         resource = new_resource;
       }
      void display();
};
