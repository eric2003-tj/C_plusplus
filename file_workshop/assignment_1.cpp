#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;
struct language {
    string lang;
    string designer;
    int date;
};
int main(){
  ifstream ifile{"languages2.txt"};
  string text;
  vector<language> vec;
  if(ifile){
    while(getline(ifile,text)){
        istringstream iss{text};
        language temp;
        iss >> temp.lang;
        string designer;
        iss >> designer;
        string temp2;
        iss >> temp2;
        while(!isdigit(temp2[0])){
            designer += " ";
            designer += temp2;
            temp2.assign("");
            iss >> temp2;
        }
        temp.designer = designer;
        temp.date = stoi(temp2);
        vec.push_back(temp);
    }
    for(auto v:vec){
        cout << v.lang << " " << v.designer << " " << v.date << endl;
    }
  }
}
