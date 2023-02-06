# Container

## Sequential container

<p>In a sequential container, the elements are stored in an order which is determined by the program. The element of the container can be accessed by the index.</p>

Example
<ol>
   <li>std::string</li>
   <li>std::vector</li>
</ol>

<p>Something worth noticed is that it can use "push_back" amd "push_front"</p>

## Associative Containers

<p>In an associative container, the elements are stored in an order which is determined by the container and depends on their value.Elements are accessed by a "key" which the container uses to look up the element</p>

Example
<ol>
   <li>std::set</li>
   <li>std::map</li>
</ol>

Some methods that can be used:

<ol>
   <li>insert() and erase()</li>
   <li>begin() and end()</li>
   <li>Algorithm-like member functions such as find() and sort()</li>
</ol>

## std::array

Some advantages:
<ol>
  <li>The number of elements is part of the type of std::array</li>
  <li>Impossible to use an std::array with the wrong number of elements</li>
  <li>std::array has a member function that returns the number of elements</li>
  <li>std::array is never converted to a pointer</li>
  <li>std::array is compatible with other STL containers</li>
  <li>Supports range checking, using the at() member function</li>
  <li>std::arrays can be assigned, if they have the same type</li>
</ol>

```
#include <iostream>
#include <array>

using namespace std;

int main() {
	// std::array can be initialized the same way as a vector
	std::array<int, 5> arr {1, 2, 3, 4, 5};

	cout << "Iterator loop: ";
	for (auto it = begin(arr); it != end(arr); ++it)         // Explicit iterator loop
		cout << *it << ", ";
	cout << endl;
	
	cout << "Range-for loop: ";
	for (auto el: arr)                                       // Range-for loop
		cout << el << ", ";
	cout << endl;
	
	cout << "Indexed loop: ";
	for (size_t i = 0; i < arr.size(); ++i)                  // Indexed loop
		cout << arr[i] << ", ";
	cout << endl;
	
	// Arrays of the same type and size can be assigned
	std::array<int, 5> five_ints;
	five_ints = arr;
	
	cout << "Elements of five_ints: ";
	for (auto el: five_ints)                                       // Range-for loop
		cout << el << ", ";
	cout << endl;
}
```

## linked_list

<p>Linked list is a data structure that uses a begining pointer and a Next pointer to connect with each other.</p>
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200922124319/Singly-Linked-List1.png">


### list In C++

```
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
	forward_list<int> l{4, 3, 1};                 // Create a list object

	cout << "Initial elements in list" << endl;
	for (auto el: l)                              // Use a range-for loop to display all the elements
	    cout << el << ", ";
	cout << endl;
	
	auto second = l.begin();
	advance(second, 1);                           // i is an iterator to the second element
	l.insert_after(second, 2);                    // Insert a new element after the first element
	
	cout << "Elements in list after inserting 2" << endl;
	for (auto el: l)
	   cout << el << ", ";
	cout << endl;

	l.erase_after(second);                        // Remove this element

	cout << "Elements in list after erasing 2" << endl;
	for (auto node: l)
	   cout << node << ", ";
	cout << endl;
}
```

## doubly_linked_list

<p>In C++, we use std::list for double-linked list</p>
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png">

```
#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> l{4, 3, 1};                       // Create a list object

	cout << "Initial elements in list" << endl;
	for (auto el: l)                            // Use a range-for loop to display all the elements
	    cout << el << ", ";
	cout << endl;
	
	auto last = end(l);
	advance(last, -1);                          // i is an iterator to the second element
	auto two = l.insert(last, 2);               // Insert a new element before the last element
	
	cout << "Elements in list after inserting 2" << endl;
	for (auto el: l)
	   cout << el << ", ";
	cout << endl;

	l.erase(two);                               // Remove this element

	cout << "Elements in list after erasing 2" << endl;
	for (auto node: l)
	   cout << node << ", ";
	cout << endl;
}
```

## operation of list

<p>Some global functions such as "sort()" do not work with list. We should call member function instead. </p>

sort
```
list<int> list1 = {4,6,9,1};
list1.sort();
```

merge
```
list<int> list1{1, 12, 6, 24};
list<int> list2{9, 3, 14};
list1.sort();
list2.sort();
list1.merge(list2); 
```

remove
```
list<int> l{4, 3, 1};
l.remove(3);                          // Remove element with value 3
```

splice

```
list<int> list1{1, 12, 6, 24};
list<int> list2{9, 3, 14};
auto p = begin(list1);
advance(p, 1);                      // p is an iterator to the second element of list1 (with value 12)
list1.splice(p, list2);             // Insert elements of list2 before p
```

splice_after()

```
forward_list<int> list1{1, 12, 6, 24};
forward_list<int> list2{9, 3, 14};
auto p = begin(list1);              // p is an iterator to the first element of list1 (with value 1)
list1.splice_after(p, list2);       // Insert elements of list2 after p
```

## deque

```
#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> dq;              // Create an empty container

	dq.push_back(5);
	dq.push_back(1);
	dq.push_front(3);           // Add element with value 3 before the other elements
	dq.push_front(2);
	dq.push_front(4);

	for (auto it: dq) {
		cout << it << ", ";
	}
	cout << endl;
}
```