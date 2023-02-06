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