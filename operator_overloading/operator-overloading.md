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
