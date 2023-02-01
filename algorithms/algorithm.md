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


