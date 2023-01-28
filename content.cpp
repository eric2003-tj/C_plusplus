#include <iostream>
#include <string>

using namespace std;

class String {
	char *data;          // Array member to store the characters
	int size;            // The number of elements in the array
public:
    String(const std::string& s) : size(s.size()) {
		data = new char[size];              // Allocate the heap memory for the data


		for (int i = 0; i < size; ++i)      // Populate the data
			data[i] = s[i];
	}
	String(const String& args){
	    size = args.size;
	    data = new char[size];
	    for(int i=0;i<size;i++){
            data[i] = args.data[i];
	    }
	}
    ~String(){
       delete[] data;
    }
    String& operator=(const String& arg){
       if(&arg != this){
          delete[] data;
          data = new char[arg.size];
          size = arg.size;
          for(int i =0;i<size;i++){
            data[i] = arg.data[i];
          }
       }
    }
	int length() {
		return size;
	}
};
int main() {
	String str("1"s);

		String str2("Two"s);
		String str3(str2);
		cout << "Str2 size: " << str2.length() << endl;
		cout << "Str3 size: " << str3.length() << endl;
		str2 = str3;
		cout << "Str2 size: " << str2.length() << endl;

	cout << "Str size: " << str.length() << endl;
}
