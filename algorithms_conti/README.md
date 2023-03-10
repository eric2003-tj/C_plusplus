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

### merge()
```
vector<int> vec1 = {1,3,2,4};
vector<int> vec2 = {1,5,6,9};
sort(begin(vec1),end(vec1));
sort(begin(vec2),end(vec2));
vector<int> vec3;
	// Merge elements from vec1 and vec2 into vec3'
merge(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));
```

### set_intersection()
```
set_intersection(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));
```

### set_union()

```
set_union(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2), back_inserter(vec3));
```
	
### reverse() and reverse_copy()

```
	vector<int> vec1 = {1,3,4};
	vector<int> vec2(vec1.size());
	reverse(begin(vec1),end(vec1));
	reverse_copy(cbegin(vec1),cend(vec1),back_inserter(vec2));
```
### rotate() and rotate_copy()
	
```
	int main() {
	vector<int> vec {1, 2, 3, 4, 5};
	
	cout << "Initial vector: ";
	print(vec);
	
	// Use the third element as the pivot
	auto pivot = begin(vec);
	advance(pivot, 2);
	
	// Perform the rotation
	auto res = rotate(begin(vec), pivot, end(vec));
	
	cout << "Result of rotate: ";
	print(vec);
	
	// res is an iterator to the element with value 1
	cout << "The original first element was " << *res << endl;
}
	// rotate_copy is similar
```

### partition() and stable_partition()

```
partition(begin(vec), end(vec), [](int n) {return n % 2 == 1;});
stable_partition(begin(vec), end(vec), [](int n) {return n % 2 == 1;}); // keep the order of the original container
bool d = is_partitioned(cbegin(vec), cend(vec), is_odd);
auto ppoint = partition_point(cbegin(vec), cend(vec), is_odd); // return an iterator
```

### sort(), is_sorted(), stable_sorted(), is_sorted_until

```
vector<int> vec{1, 4, 5, 6, 2, 7, 5};
sort(begin(vec), end(vec),
                 [](int m, int n) { return m > n; }
	);
stable_sort(begin(vec), end(vec), [](int m, int n) { return m > n; }); 
is_sorted(cbegin(vec), cend(vec)); // return a boolean
auto el = is_sorted_until(cbegin(vec), cend(vec)); // return an iterator
```

### partial_sort()

```
auto it = begin(keys);
partial_sort(it, it + 5, end(keys));
```
### partial_sort_copy()

```
string keys {"qwertyuiopasdfghjkl"};
string dest(5, ' ');
	
cout << "keys: " << keys << endl << endl;
partial_sort_copy(cbegin(keys), cend(keys), begin(dest), end(dest)); // depending on the size of the destination
```

### nth_element()

```
nth_element(begin(vec), mid, end(vec));
```

### next_permutation()

```
string str{"abc"}; // needed to be ascending order
do{
  cout << str << endl;
  }while(next_permutation(begin(str),end(str));

```

### prev_permutation()
<p> Same as above codes but needed to be descending order.</p>

### is_permutation()

<p>Return whether they have same permutation</p>

### partial_sum()

```
vector<int> vec1 = {1,2,3,4,5};
vector<int> vec2;
partial_sum(cbegin(vec1),cend(vec1),back_inserter(vec2));
```
	
### adjacent_difference()
	
```
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void print_vec(const vector<int>& vec) {
	for (auto v : vec)
		cout << v << ", ";
	cout << endl;
}

int main() {
	vector<int> vec1 {1, 3, 6, 10, 15 };
	vector<int> vec2;
	
	cout << "Source vector: ";
	print_vec(vec1);
	
	adjacent_difference(cbegin(vec1), cend(vec1), back_inserter(vec2));
	
	cout << "Target vector: ";
	print_vec(vec2);
}
```
### inner_product()

```
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void print_vec(const vector<int>& vec) {
	for (auto v : vec)
		cout << v << ", ";
	cout << endl;
}

int main() {
	vector<int> vec1 {1, 3, 6, 10, 15 };
	vector<int> vec2{ 1, 2, 3, 4, 5 };
	
	cout << "vec1: ";
	print_vec(vec1);
	cout << "vec2: ";
	print_vec(vec2);
	
	auto result = inner_product(cbegin(vec1), cend(vec1), cbegin(vec2), 0);
	
	cout << "The inner product of vec1 and vec2 is: " << result << endl;
}
```

### inner_product() overload
	
```
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector<double> expected{ 0.1, 0.2, 0.3, 0.4, 0.5 };
	vector<double> actual{ 0.09, 0.22, 0.27, 0.41, 0.52 };
	
	auto max_diff = inner_product(
								begin(expected), end(expected), begin(actual), 0.0,
                               [](auto a, auto b){ return max(a,b); },          // Reduce operation
							   [](auto l, auto r) { return fabs(r-l); });       // Transform operation 

	cout << "Max difference is: " << max_diff << endl;
}
```

## random number in C++(traditional)

### rand()

```
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	// Print out a pseudo-random integer
	cout << "Printing out a random number... ";
	cout << rand() << endl;
}
```

### rand_range

```
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	// Print out a pseudo-random floating-point number with value between 0 and 1
	cout << 1.0*rand()/RAND_MAX << endl;            // Convert the result to double!

	// Print out ten pseudo-random integers with value between 1 and 100
	for (int i = 0; i < 10; ++i)
		cout << (99*rand()/RAND_MAX + 1) << endl;
}
```

### seed

```
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));  // Use current time as seed
	
	// Print out a pseudo-random floating-point number with value between 0 and 1
	cout << 1.0*rand()/RAND_MAX << endl;            // Convert the result to double!

	// Print out ten pseudo-random integers with value between 1 and 100
	for (int i = 0; i < 10; ++i)
		cout << (99*rand()/RAND_MAX + 1) << endl;
}
```

## random number in modern C++

### engine

```
#include <iostream>
#include <random>

using namespace std;

int main() {
	default_random_engine eng;                        // Create engine object - generates sequence

	cout << "Five random integers:\n";
	for (int i = 0; i < 5; ++i ) {
		cout << eng() << ", ";                        // Call the functor to get the next number
	}
	cout << endl;
}
```

### distribution()

```
#include <iostream>
#include <random>

using namespace std;

int main() {
	random_device rd;                                 // Random device (or maybe not!)   
	mt19937 mt(rd());                                 // Seed engine with number from random device

	uniform_int_distribution<int> idist(0, 100);      // We want ints in the range 0 to 100

	cout << "Five random integers between 0 and 10:\n";
	for (int i = 0; i < 5; ++i ) {
		cout << idist(mt) << ", ";                    // Call the functor to get the next number
	}
	cout << endl << endl;

	uniform_real_distribution<double> fdist(0, 1);    // Doubles in the range 0 to 1

	cout << "Five random floating-point numbers between 0 and 10:\n";
	for (int i = 0; i < 5; ++i ) {
		cout << fdist(mt) << ", ";
	}
	
	cout << endl;
}
```

```
#include <iostream>
#include <random>

using namespace std;

int main() {
	mt19937 mt;                                       // Create engine object - generates sequence

	uniform_int_distribution<int> idist(0, 10);       // We want ints in the range 0 to 100

	cout << "Five random integers between 0 and 10:\n";
	for (int i = 0; i < 5; ++i ) {
		cout << idist(mt) << ", ";                    // Call the functor to get the next number
	}
	cout << endl << endl;

	uniform_real_distribution<double> fdist(0, 10);    // Doubles in the range 0 to 10

	cout << "Five random floating-point numbers between 0 and 10:\n";
	for (int i = 0; i < 5; ++i ) {
		cout << fdist(mt) << ", ";
	}
	cout << endl;
}
```

## algorithms with random numbers

### shuffle

```
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

int main() {
	vector<int> vec {3, 1, 4, 1, 5, 9};
	static mt19937 mt;
	
	cout << "Vector before shuffling\n";
	for (auto v : vec)
		cout << v << ", ";
	
	shuffle(begin(vec), end(vec), mt);
	
	cout << "\nVector after shuffling\n";
	for (auto v : vec)
		cout << v << ", ";
	cout << endl;
}
```

implementation

```
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <iterator>

using namespace std;

void print( const vector<int>& vec) {
	ostream_iterator<int> oi(cout, ", ");
	copy(vec.begin(), vec.end(), oi);
}

int main() {
	vector<int> vec {3, 1, 4, 1, 5, 9};
	static mt19937 mt;
	
	cout << "Vector before shuffling\n";
	print(vec);
	
	uniform_int_distribution<int> uid(0, vec.size()-1);
	
	for (int i = 0; i < vec.size(); ++i) {
		std::swap(vec[i], vec[uid(mt)]);
	}
	
	cout << "\nVector after shuffling\n";
	print(vec);
	cout << endl;
}
```

### bernouli

```
#include <iostream>
#include <random>

using namespace std;

int main() {
	static mt19937 mt;
	static bernoulli_distribution bd;

	if (bd(mt))
		cout << "Your subjects are grateful for your wise and benevolent rule\n";
	else
		cout << "The peasants are revolting!\n";
}
```
