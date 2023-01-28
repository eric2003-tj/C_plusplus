# Files and Streams
## Read a file
<p>
    In C++, we can import <fstream> and use ifstream to read a file.
</p>
    
```
    #include <iostream>
    #include <fstream>
    using namespace std;
    int main(){
       ifstream ifile{"text.txt"}; // read a file
       if(ifile){ // check file is open successfully
          string text{""};
          while(ifile >> text){ //put one word to text
            cout << text << " ";
          }
       }
   }
```
<p>
    Furthermore, we can use getline(file,text) to read a line directly.
</p>
    
```
    #include <iostream>
    #include <fstream>
    using namespace std;
    int main(){
       ifstream ifile{"text.txt"}; // read a file
       if(ifile){ // check file is open successfully
           string text{""};
           while(getline(ifile,text)){
             cout << text << " ";
         }
       }
   }
    
```
    
## How to write a file
<p>Sililarly, we can use ofstream to write things to a file </p>
    
```
    #include <iostream>
    #include <fstream>
    int main(){
       ofstream ofile{"text_out.txt"};
       if(ofile){
         vector<string> vec = {"dddd","xxxxx","apple"};
         for(auto v:vec){
            ofile << v << ",";
         }
         ofile.close();
       }
    }
```
    
## buffer and flush
    
<p>When writing a file, the compiler will not write the data to the file until the buffer of the stream is full. This will cause some problems when the program is suddenly terminated. To avoid the data lost, we can flush the buffer every time with keyword "flush" or "endl". </p>

```
     cout << i << '\n' << flush;
     ofile << i << '\n' << flush; // equivalent to endl func
```

## cin.get() and cout.put()
<p>
   We can read one character at a time(using cin.get()) ,and output it one at a time(using cout.put())    
</p>

```
#include <iostream>
using namespace std;
int main(){
   char c;
   while(cin.get(c)){
      cout.put(c);
   }
}
```
    
## read() and write() in C++

```
#include <iostream>
#include <fstream>
using namespace std;
int main(){
   const int file_size{10};
   char buffer[file_size];
   ifstream ifile{"input.txt"};
   ifile.read(buffer,file_size); // let buffer stores the data of the file
   auto nread = ifile.gcount();
   ifile.close();
   cout << nread << endl;
   cout.write(buffer,file_size);
}
```

## file's modes in C++
    
| mode | functionality |
| ---| ---|
| appending mode | write from the back of the file |
| binary mode | using binary codes to store data|
| trunc mode | The file is opened in trunc mode by default, the data originally in the file will be lost|
| in mode | ifstream |
| out mode| ofstream |

```
int main(){
   ofstream ofile;
   ofile.open("input.txt",fstream::app); //appending modes
   ofile << "\n123456789";
   ofile.close();
}
```
<p>
   If we want to open a file with multiple modes, we use "|" to differentiate the modes.    
</p>

## states in C++

<ul> 
    <li>cin.good() -- successfully read in the data</li>
    <li>cin.fail() -- Something went wrong when reading the data, but it can be recovered</li>
    <li>cin.bad() -- Something went wrong when reading the data, but it can not be recovered</li>
</ul>
    
## Error handling with C++ -- using cin.ignore()

<p>
   There are two important methods in cin...
   <ol>
       <li>cin.ignore(size,delimiter)---It will discard next size inputs and stops ignoring when it reads delimiter</li>
       <li>cin.clear()--- clear the buffer of cin stream</li>
   </ol>
</p>

```
#include <iostream>
#include <limits>

using namespace std;

int main() {
	int x{0};

	cout << "Please enter a number: ";
	cin >> x;

	bool success{false};
	while (!success) {
		if (cin.good()) {
			cout << "You entered the number " << x << "\n";
			success = true;
		}
		else if (cin.fail()) {
			cout << "Please try again and enter a number\n";
			cin.clear();
			//cin.ignore(20, '\n');                // Remove next 20 characters or everything up to next newline
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> x;
		}
	}
}
```
    
## Formatting with <iomanip>

| methods | functionality |
| --- | --- |
| setw(int width) | set the width of output is 15pixels|
| left | left-aligned |
| right| right-aligned|
| setfill(char c) | set the empty space filled with c |
| boolalpha | make the booleed as true and false|
| setprecision() | set the digits of the double|
| scientific | set the intepretation of the numeric numbers to scientific notation|

```
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int main() {
	cout << boolalpha << (2==3) << endl;
	cout <<left<< setw(15) << "My dog:" << "Brenden";
	cout << endl;
	cout << right;
	cout << setfill('#');
	cout << setw(15) << "My dad" << "Yellow";
}
```
# stringstream
<p>
  To use stringstream, it is necessary to import <sstream>    
</p>
    
## ostringstream
```
#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
    ostringstream os;
    cout << "Please enter an word:" << '\n';
    string text;
    cin >> text;
    os << text;
    cout << "please enter another word: " << endl;
    cin >> text;
    os << text;
    cout << os.str() << endl; // print the content of the os
}
```

## istringstream
    
```
#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream ifile("input.txt");
    string text;
    vector<int> vec;
    while(getline(ifile,text)){
        istringstream in(text);
        int num;
        while(in >> num){
            vec.push_back(num);
        }
    }
    for(auto n:vec){
        cout << n << endl;
    }
}
```

## random access of the stringstream

<p>
  We can use tellp and seekp to find certain position of the streamstring in ostringstream; tellg and seekg in istringstream    
</p>

```
#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ostringstream output;                                   // Open an output stringstream

	string data{"It is time to say "};
    output << data;                                         // Write some data to the stream

    auto marker = output.tellp();                           // Save current file position marker
	cout << data.size() << " characters written to stream\n";
	cout << "Stream marker is " << marker << " bytes into the stream\n";

	output << "hello";                                      // Write some more data to the stream
	cout << "Stream marker is now " << output.tellp() << " bytes into the stream\n";

	cout << output.str() << endl;

    if (marker != -1)                                       // We have changed our mind!
        output.seekp(marker);                               // Move marker back to original position

	output << "goodnight";                                  // Write some data to stream

	cout << output.str() << endl;
}
```
    
## ostringstream iterator
```
#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    ostream_iterator<int> oi(cout,"\n");
    for(int i=0;i<10;i++){
        *oi = i; //dereferencing is not necessary
        oi++;
    }
}
```
                          
## istringstream iterator
                          
```
#include <iostream>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    istream_iterator<string> ii(cin);
    istream_iterator<string> eof;
    vector<string> vs;
    while(ii != eof){
        vs.push_back(*ii);
        ii++;
    }
    for(auto v:vs){
        cout << v << endl;
    }
}
```







