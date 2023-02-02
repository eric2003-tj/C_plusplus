# algorithms

## searching_algorithms

### find_first_of series

```
#include <string>
#include <iostream>

using namespace std;

int main() {
	string str {"Hello world"};
	cout << "String to search: " << str << endl;
	
	string vowels {"aeiou"};
	cout << "First vowel is at index " << str.find_first_of(vowels) << endl;
	cout << "Last vowel is at index " << str.find_last_of(vowels) << endl;
	cout << "First non-vowel is at index " << str.find_first_not_of(vowels) << endl;
	cout << "Last non-vowel is at index " << str.find_last_not_of(vowels) << endl;
}
```

### find()

```
#include <string>
#include <iostream>

using namespace std;

int main() {
	string str{"Hello world"};
	cout << "String to search: " << str << endl;

	size_t pos = str.find('o');

	if (pos != string::npos) {
		cout << R"(First occurrence of 'o' is at index )" << pos << endl;
	}
	else {
		cout << R"(Could not find 'o' in the string)" << endl;
	}

	pos = str.find("or");

	if (pos != string::npos) {
		cout << R"(First occurrence of "or" is at index )" << pos << endl;
	}
	else {
		cout << R"(Could not find "or" in the string)" << endl;
	}

	pos = str.find('O');

	if (pos != string::npos) {
		cout << R"(First occurrence of 'O' is at index )" << pos << endl;
	}
	else {
		cout << R"(Could not find 'O' in the string)" << endl;
	}
}
```

<p>We can also use rfind() method</p>

```
#include <string>
#include <iostream>

using namespace std;

int main() {
	string str {"Hello world"};
	cout << "Initial contents of str: " << str << endl;
	
	size_t pos = str.rfind('o');
	
	if (pos != string::npos) {
		str[pos] = 'p';
	}
	else {
		cout << "Could not find the search string\n";
	}
	
	cout << "Final contents of str:   " << str << endl;
}
```

### adjacent_find
```
 auto pos = adjacent_find(cbegin(str),cend(str));
```

### search_n
```
 auto pos2 = search_n(cbegin(vec),cend(vec),4,3);
```

### search 

```
auto pos3 = search(cbegin(str),cend(str),cbegin(temp),cend(temp));
```

### mismatch

<p>mismatch() takes two iterator ranges and looks for differences between the two ranges. It returns a pair to the first element that has a different value in each range</p>

```
vector<int> vec1{1, 2, 2, 3, 2, 3, 3};
vector<int> vec2{1, 2, 2, 2, 2, 3, 3}; 
auto enem = mismatch(cbegin(vec1),cend(vec1),cbegin(vec2),cend(vec2));
```

### some_of method

<ol>
   <li>all_of() returns true if the predicate is true for every element</li>
   <li>any_of() returns true if the predicate is true for at least one element</li>
   <li>none_of() returns true if the predicate is false for every element</li>
</ol>

```
  none_of(cbegin(vec), cend(vec), is_odd);
  any_of(cbegin(vec), cend(vec), is_odd);
  all_of(cbegin(vec), cend(vec), is_odd); //is_odd is a lambda expression
```

### binary_search

```
binary_search(cbegin(vec), cend(vec), 4);
```

### includes
<p>includes() returns a bool, depending on whether all the elements in the
second range are present in the first range</p>

```
includes(cbegin(str), cend(str), cbegin(vowels), cend(vowels));
```