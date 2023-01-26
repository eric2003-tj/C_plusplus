#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct language {
    string lang;
    string designer;
    int date;
};
int main(){
  ifstream ifile{"languages.txt"};
  string text;
  vector<string> vec;
  if(ifile){
    while(ifile >> text){
        vec.push_back(text);
    }
  }
  auto beg_pos = vec.begin();
  for(auto it=vec.begin();it!=vec.end();it++){
    cout << *it;
    if((it-beg_pos)%3 == 2){
        cout << endl;
    }else{
        cout << " ,";
    }
  }
}
