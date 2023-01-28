# Iterator

## What is iterator?

<p>
    Iterator is a tool to use to go through a container such as vector and string. In C++, it is a convenient tool to use to simplify our codes.
</p>
<br>

## Go through a string
```
#include <iostream>
#include <string>
   int main(){
       string hello{"Hello World!"};
       for(string::iterator it = hello.begin();it!=hello.end();it++){
          cout << *it << ",";
       }
   }
   
```

<p>
    In above codes, we can use string::iterator to go through a string. In addition, it is a memory address therefore we should dereference it to get the value. 
</p>

## Go through vector
<p>
    Similarly, we can write the codes below to go through a vector.
</p>

```
#include <iostream>
#include <vector>
using namespace std;
int main(){
   vector<int> arr = {3,4,5,6,9};
   for(vector<int>::iterator it = arr.begin();it!=arr.end();it++){
      cout << *it << ",";
   }
}
```

## auto keyword

<p>
    Sometimes we have difficulty recognizing the type of the iterator, or sometimes we just want to simplify our codes, we can use the keyword: auto.
    What auto does is to make compilers recognize the type of the variables,belows are some examples.
</p>

### simplify for loop

```
#include <iostream>
#include <vector>
using namespace std;
int main(){
   vector<int> vec = {1,2,6,8,9,2,5};
   for(auto it = vec.begin(); it!= vec.end();it++){
     cout << *it << ' ';
   }
}
```

### variable declaration

```
  #include <iostream>
  #include <string>
  using namespace std;
  int main(){
     auto i{5};
     auto str{"Hello world!"};
  }
```