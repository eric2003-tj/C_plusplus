# operator-overloading

## friend keyword

<p>
   In order to access a class's private field instance, we can use friend keyboard.
</p>

```
#include <iostream>
#include <string>

using namespace std;

class Test {
	int i{42};
	string s{"Hello"};
public:
	friend class Example;
};

class Example {
	public:
	void print(const Test& test) {
		cout << "i = " << test.i << ", s = " << test.s << endl;
	}
};

int main() {
	Test test;
	Example ex;
	ex.print(test);
}
```

## Members and non-members operators

<p>In general, it is better for programmers to implement member functions. The advantages are as belows.</p>

<ol>
   <li>Direct access to private data</li>
   <li>All class-related code is in the same place</li>
</ol>

<p>However, sometimes it is better to use non-member function. For instance,</p>

```
#include <iostream>
#include <string>

using namespace std;

class String {
	string s;
public:
	// Constructors
	String(const char* str): s(str) {}
	String(const string& s): s(s) {}

	String operator +(const String& arg) {
		return s + arg.s;
	}
	
	void print() { cout << s << endl; }
};

int main() {
	String w{"world"}, bang{"!"};
	String wbang = w + bang;                         // Calls w.operator + (bang); OK
	String hi = "hello " + w;                        // Cannot call "hello".operator + (w); Compiler error! 
	cout << "wbang: "; wbang.print();
	cout << "hi: "; hi.print();
}
```
<p>If we implement non-member function</p>

```
#include <iostream>
#include <string>

using namespace std;

class String {
	string s;
public:
	// Constructors
	String(const char* str) : s(str) {}
	String(const string& s) : s(s) {}
	
	friend String operator +(const String& arg1, const String& arg2);
	
	void print() { cout << s << endl; }
};

String operator +(const String& arg1, const String& arg2) {
	return arg1.s + arg2.s;
}

int main() {
	String w { "world" }, bang { "!" };
	String wbang = w + bang;
	String hi = "hello " + w;
	cout << "wbang: "; wbang.print();
	cout << "hi: "; hi.print();
}
```

## addition

<p>We use complex as an example for overloading, we defined "+=" as a member function of complex, and then defined a global functiom for addition</p>

```
class Complex {
private:
	double real{0.0};
	double imag{0.0};
public:
	Complex(double r, double i): real(r), imag(i) {}
	Complex(double r): real(r) {}

	// We define the += operator as a member function
	// This adds the real and imaginary parts separately and returns the modified object
	Complex& operator +=(const Complex& rhs) {
		real += rhs.real;                     // Assign new value of real member
		imag += rhs.imag;                     // Assign new value of imag member
		return *this;                         // Return modified object by value
	}
	void print() {
		cout << "(" << real << ", " << imag << ")" << endl;
	}
};

Complex operator + (const Complex& lhs, const Complex& rhs) {
	Complex temp{lhs};                       // Make a copy of the lhs argument
	temp += rhs;                              // Add the rhs argument to it
	return temp;                              // Return the modified copy of the lhs argument
}
```

## comparison

<p>Based on mathematics, if we defined less than operator  and equal operator, then we can do every comparison</p>

```
class student {
    std::string name;                  // Student's name - not necessarily unique
    int id;                            // Student's ID number - unique to each student
public:
	student(std::string name, int id) : name(name), id(id) {}
	friend bool operator ==(const student& lhs, const student& rhs);
	friend bool operator !=(const student& lhs, const student& rhs);
	friend bool operator <(const student& lhs, const student& rhs);
	void print();
};
--------------------------
bool operator ==(const student& lhs, const student& rhs) {
	if (lhs.name == rhs.name) {
		return true;
	}
	return false;
}
bool operator !=(const student& lhs, const student& rhs) {
	return !(lhs == rhs);
}

bool operator <(const student& lhs, const student& rhs) {
	return (lhs.name < rhs.name);               // Order by name (alphabetical sort)
}
```

## func pointer

```
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
using namespace std;
void func(int a,int b){
  cout << a << " + " << b << " = " << a+b;
  return ;
}
using pfunc = void(*)(int,int);
pfunc other_func(){
   return &func;
}
int main(){
   int a{5};
   int b{3};
   auto fun_ptr = &func; // making a pointer point to func
   (*fun_ptr)(a,b);
   cout << endl;
   (*other_func())(a,b);
}
```

## function overload

```
#include <iostream>
#include <vector>

using namespace std;

class evenp {
public:
	bool operator() (int n) {
		return (n % 2 == 0);
	}
};

void do_it(const vector<int>& vec, evenp is_even) {
	for (auto v: vec)
		if (is_even(v))
			cout << v << " is even\n";
}

int main() {
	evenp is_even;                               // Create a functor object

	vector<int> numbers{1, 4, 7, 11, 12, 23, 36}; // Vector of numbers

	cout << "Vector: ";
	for (auto number : numbers)
		cout << number << ", ";
	cout << endl;

	do_it(numbers, is_even);                 // Pass functor as argument to a function call
}
```