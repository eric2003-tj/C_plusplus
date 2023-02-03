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

## numeric algorithms

<p>Since some of the algorithms about number are not defined in the <algorithms>, we should use <numeric></p>

### iota

```
iota(begin(vec), end(vec), 1);                  // Populate the vector elements as 1, 2, 3, 4, ...
```

### accumulate

```
auto sum = accumulate(cbegin(vec), cend(vec), 0);           // Returns the sum of the elements
auto sum = accumulate(cbegin(vec), cend(vec), 0,
		[] (int sum, int n) {  return (n % 2 == 1) ? sum + n : sum; }
	);
```

### reduce

```
auto sum = reduce(begin(vec), end(vec), 0);           // Sum elements of vec using initial value 0
```

## write-only algorithms

### fill 

```
fill(begin(vec), end(vec), 42);                   // Assign 42 to all its elements
```

### fill_n

```
auto begin_rest = fill_n(begin(vec), 5, 42);
```

### generate()

```
class square {
  private:
    int n{0};
  public:
    int operator()() { ++n; return n * n; }
};

int main() {
	vector<int> vec(10);                                 // Vector with 10 elements
	generate(begin(vec), end(vec), square());  
}          // Populate it with the first 10 squares
```

### generate_n()

```
generate_n(back_inserter(vec), 10, square()); 
```

### for_each()

```
for_each(begin(str), end(str), 
			[](char& c) { c = toupper(c); }
	);
/*
for (auto& c: str2)
		 c = toupper(c);
*/
```

### copy()

```
copy(cbegin(vec), cend(vec), begin(vec2));
```

### copy_n()

```
copy_n(cbegin(vec),cend(vec),2,begin(vec2));
```

### copy_if()

```
copy_if(cbegin(vec),cend(vec),begin(vec2),lambda_expression);
```

### replace()

```
replace(begin(vec),end(vec),1,2); // replace 1 with 2
```

### replace_if()

```
replace_if(begin(vec),end(vec),[](int n){return (n%2==0);},2);
```

### replace_copy()

```
replace_copy(cbegin(vec1), cend(vec1), back_inserter(vec2), 1, 2);
```

### replace_copy_if()

```
replace_copy_if(cbegin(vec1), cend(vec1), back_inserter(vec2),
                         [] (int n) { return (n % 2 == 0); },
                         6);
```

### remove() and erase()
```
auto defunct = remove(begin(vec),end(vec),1);  // put 1 in the back of the vec and return the first "1"'s address
vec.erase(defunct,end(vec));
```

### remove_if()

```
auto defunct = remove_if(begin(vec),end(vec),[](int n){return (n%2==0);});
vec.erase(defunct,end(vec));
```

### remove_copy()

```
auto defunct = remove_copy(begin(vec),end(vec),begin(vec2),1);
vec2.erase(defunct,end(vec2));
```

### remove_copy_if()

```
 auto defunct = remove_copy_if(begin(vec),end(vec),begin(vec2),[](int n){return (n%2==0);});
 vec2.erase(defunct,end(vec2));
```

### unique()

<p>Notice that unique() only deals with adjacent elements of the container</p>

```
    auto defunct = unique(begin(vec), end(vec));
	
	cout << "Before calling erase, the vector has " << vec.size() << " elements\n";
	vec.erase(defunct, end(vec));
	
	cout << "After calling erase, the vector has " << vec.size() << " elements\n";
	
	for (auto v : vec)
		cout << v << ", ";
	
```

### unique_copy()

```
unique_copy(cbegin(vec), cend(vec), back_inserter(vec2), 
						[] (int m, int n) { return (n == m + 1); }
);
```

### transform()

```
transform(cbegin(vec),cend(vec),begin(vec2),[](int n){return n*2;});
```

```
// inplace
transform(begin(vec), end(vec), begin(vec),
		[](int n) { return 2*n; }
	);
```

```
// overload
transform(cbegin(vec1), cend(vec1), back_inserter(vec2),
        	       	      [] (int n) { return 2*n; }
	);
```

```
transform(begin(lhs_copy), end(lhs_copy), begin(lhs_copy), ::toupper);
transform(begin(rhs_copy), end(rhs_copy), begin(rhs_copy), ::toupper);
```