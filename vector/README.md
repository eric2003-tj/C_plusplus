# C++ vector
## declaration
<p>
   Remember to import include <vector>    
</p>

```
  #include <iostream>
  #include <vector>
  int main(){
      std::vector<int> vec = {1,2,3};
  }
```

## push_back
<p>
  If we want to add an element in the end of the vector, we need to use push_back() method to do this.
</p>
    
### add "7" in the back of vector
    
```
  #include <iostream>
  #include <vector>
  int main(){
      std::vector<int> vec = {1,2,3};
      vec.push_back(7);
  }
```
    
## pop_back()

<p>
  We can use pop_back() to remove the last element in the vector    
</p>
    
### remove "7" in the back of vector
    
```
  #include <iostream>
  #include <vector>
  int main(){
      std::vector<int> vec = {1,2,3};
      vec.push_back(7);
      vec.pop_back();
  }
```

    