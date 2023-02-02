# algorithm in C++

## algorithm overview

<p> In C++, we can introduce "#include <algorithm>" to import useful algorithm to help us reduce the complexcity of the codes.</p>

## find()

```
#include <iostream>
#include <string>
#include <algorithm>

int main(){
    string str{"hello world"};
    auto res = find(cbegin(str), cend(str), 'l'); 
    if(res != cend(str)){
        cout << *res << " at " << distance(cbegin(str),res);
    }
}

```

## predicate

<p>In order to use STL function of C++, we need to learn about predicate.</p>

<p>We use sort() as our example:</p>

```
/// before using predicate
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> names = { "Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally" };
	
	cout << "Vector before sort()\n";
	for (auto name : names)
		cout << name << ", ";
	cout << endl << endl;
	
	sort(begin(names), end(names));
	
	cout << "Vector after sort()\n";
	for (auto name : names)
		cout << name << ", ";
	cout << endl;
}

// result : Alice, Asok, Dilbert, Dogbert, PHB, Ted, Wally,
```

```
/// Using predicate
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Define a predicate function
bool is_shorter (const string& lhs, const string& rhs) {
    return lhs.size() < rhs.size();
 }

int main() {
	vector<string> names = { "Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally" };
	
	cout << "Vector before sort()\n";
	for (auto name : names)
		cout << name << ", ";
	cout << endl << endl;
	
	// Sort the data in alphabetical order
	sort(begin(names), end(names));
	
	cout << "Sorted alphabetically:" << endl;
	vector<string>::iterator it;
	for (auto name : names)
		cout << name << ", ";
	cout << endl;
	
	// Sort the data, passing the function pointer as the predicate
	sort(begin(names), end(names), is_shorter);
	
	cout << endl << "Sorted by length:" << endl;
	for (auto name : names)
		cout << name << ", ";
	cout << endl;
}
```

## find_if()

```
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Functor
class ge_5 {
	public:
	// Overloaded () operator
	// Takes an std::string, returns true if more than 5 characters
    bool operator ()(const string& s) const { 
      return (s.size() > 5);
    }
};

int main() {
	// Manually coded example
	vector<string> names = { "Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally" };
	
	ge_5 long_enough;
	for (auto name: names) {
		if (long_enough(name)) {
			cout << "Loop: the first name with > 5 characters is \"" << name << "\"\n";
			break;
		}
	}
	
	// Find the first element with more than 5 characters
	// Pass a functor object as predicate
	auto res = find_if(cbegin(names), cend(names), ge_5());

	// Display it
	if (res != cend(names))
		cout << "Algorithm: the first name with > 5 characters is \"" << *res << "\"\n";
}
```

## lambda

```
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
    vector<int> vec = {4,9,6,3,1,2};
    sort(begin(vec),end(vec),[](int lhs,int rhs){return (rhs<lhs);});
    for(auto n:vec){
        cout << n << ",";
    }
}
```
## some important features about lambda expressions

<p>By default, lambda expression has very limited access to variables. It only has access to non-local variables.</p>

```
// demo
#include <iostream>

using namespace std;

int global{99};                                  // Non-local variable

int main() {                                     // Scope containing the lambda expression
	static int answer{42};                       // Static variable in containing scope
	const int one{1};                            // Local variable in containing scope
	const int& r_one{one};                       // Local variable in containing scope
	
	[]() {                                       // Start of lambda body
		cout << global << endl;                  // Lambda body can access non-local variables
		cout << answer << endl;                  // Lambda body can access static variables
		// Does not compile with Visual C++
		//cout << one << endl;                   // Lambda body can read local variables, provided...
		// Does not compile with Visual C++, gcc or clang
		//cout << r_one << endl;                 // Lambda body can read local variables, provided...
	};                                           // End of lambda body
}                 
```

<p>If we want it to have access to local variables, we need to add the variable name in the []</p>

```
//demo
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	vector<string> words{ "a", "collection", "of", "words", "with", "varying", "lengths" };

	int n{5};
	// Find the first element with more than 5 characters
	auto res = find_if(cbegin(words), cend(words), 
				[n] (const string& str) { return str.size() > n; }         // Lambda captures local variable n
	);

	// Display it
	if (res != cend(words)) {
		cout << R"(The first word which is more than )" << n << R"( letters long is ")";
		cout << *res << R"(")" << endl;
	}
}
```

<p>However, by default, the local variable passed into lambda expression is const, if we wanna change it, we should add a keyword "mutable"</p>

```
// demo
int main() {
	vector<string> words{ "a", "collection", "of", "words", "with", "varying", "lengths" };

	int n{5}, idx{-1};                                // Add another variable for the index of the match
	auto res = find_if(cbegin(words), cend(words),
//					[n, idx] (const string& str) { ++idx; return str.size() > n; }              // Error!
					[n, idx] (const string& str) mutable { ++idx; return str.size() > n; }      // OK
	 );

	if (res != cend(words)) {
		cout << R"(The first word which is more than )" << n << R"( letters long is ")";
		cout << *res << R"(")" << endl;
		cout << "The index is " << idx << endl;                // Always prints zero
	}
}
```

<p>In above examples, lambda captures variables by value, and that is to say, the real value of the local variable is never changed. In order to change the value, we can let lambda capture it by reference.</p>

```
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
using namespace std;
int main(){
    vector<string> vec = {"assd","bhhsdf","dfdfdd"};
    int max{5};
    int idx{-1};
    auto res = find_if(cbegin(vec),cend(vec),[max,&idx](const string& str){++idx; return str.size() > max;});
    cout << idx << endl;
}
```

### implicit capture

<p>In an implicit capture, all variables in scope are captured by the lambda
expression</p>

<ul>
   <li>[=] for implicit capture by value</li>
   <li>[&] for implicit capture by reference</li>
   <li>We can exclude some variables from implicit capture.[=, &x] will capture x by reference, all others by value. Only x can be modified
by the lambda</li>
<li>[&, =a, =b] will capture a and b by value, all others by reference. a and b
cannot be modified by the lambda</li>
</ul>

<p>Please notice that "mutable" does not needed when capturing by ref.</p>

### lambda with this
<p>When "this" is used, it represents capturing by ref of the object. If we wanna capture by value, we need to use "*this".</p>

### partial evaluation
```
#include <iostream>
#include <string>

using namespace std;

// Function which returns a lambda function
auto greeter(const string& salutation) {
	return [salutation](const string& name) { return salutation + ", "s + name; };       // The lambda function
}

int main() {
	// Store the lambda function in a variable
	auto greet = greeter("Hello"s);

	// Call the lambda function
	cout << "Greeting: " << greet("James") << endl;
	cout << "Greeting: " << greet("students") << endl;

	auto greet_formal = greeter("Good morning"s);

	// Call the lambda function
	cout << "Formal greeting: " << greet_formal("Dr Stroustrup") << endl;
}
```

### lambda generalize

```
#include <iostream>

using namespace std;

int main() {
	auto add_two = [y=2] (int x) { return x + y; };                 // y is local to the lambda body
	cout << "Calling add_two(2) gives " << add_two(2) << endl;
	cout << "Calling add_two(5) gives " << add_two(5) << endl;
}
```

## equal

<p>We can check whether two containers are the same using equal()</p>

```
// using string as an example
equal(cbegin(lhs), cend(lhs), cbegin(rhs), cend(rhs),
               		           [] (char lc, char rc) { return toupper(lc) == toupper(rc); }
```

## pair

<p> pair is a data structure that contains two datas, first and second. In addition, the most important feature of this data structure is that all of its members are public.</p>

```
// declare
pair<string, string> wordpair{"hello", "there"};
auto wordpair { make_pair("hello", "there") };
pair wordpair{"hello"s, "there"s};                         // C++17 CTAD

```

