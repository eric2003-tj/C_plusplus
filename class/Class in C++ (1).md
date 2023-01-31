# Class in C++

## create a class

```
  class item{
    private:
      int price;
      double tax; //instance fields
      std::string name;
    public:
      ....
  }
```

## basic methods

### constructor
1.
    ```
      item(int new_price,double new_tax,std::string new_name){
         price = new_price;
         tax = new_tax;
         name = new_name;
      }
    ```
2.
    ```
      item(int new_price,double new_tax,std::string new_name):price(new_price),tax(new_tax),name(new_name){}
    ```
<br>

### member getters and member setters
<br>
<p>
    Since the instance fields of an object are private by default, we cannot access the them directly. In order to tackle with the values, we need to introduce getters and setters(public methods);
</p>

```
  class item{
    private:
      int price;
      double tax; //instance fields
      std::string name;
    public:
      item(int new_price,double new_tax,std::string new_name){
         price = new_price;
         tax = new_tax;
         name = new_name;
      }
      // getters
       int get_price(){
         return price;
      }
      double get_tax(){
        return tax;
      }
      std::string get_name(){
        return name;
      }
      // setters
      void set_price(int new_price){
        price = new_price;
      }
      void set_tax(double new_tax){
        tax = new_tax;
      }
      void set_name(std::string new_name){
        name = new_name;
      }
  }
```

### copy constructor 

<p>
    In C++, if you use a object to create another object , compiler will deal with the task automatically. But sometimes, you are not willing to the result created by the compiler, and that is the time you need to write the copy constructor on your own.
</p>

```
  item(const item& other){
     price = other.price;
     tax = other.tax;
     name = other.name;
  }
```

### assignment operator

<p>
   We can use assignment operator to create a new object.    
</p>


```
  item &operator =(const item& arg) 
  {
	price = arg.price;
        tax = arg.tax;
        name = arg.name;
	return *this;
    }
```

### shallow copy and deep copy


<ol>
    <li><strong>shallow copy</strong> : shallow copy aims to copy all the member's values of the source object copying into target object. But there is a fatal problem, if the member is a pointer, shallow copy will cause the two objects sharing the same address.</li>
    <li><strong>deep copy</strong> : the members of two objects all have different memory address</li>
</ol>

```
class String {
	char *data;          // Array member to store the characters
	int size;            // The number of elements in the array
public:
    // shallow copy
    String(const std::string& s) : size(s.size()) {
		data = new char[size];              // Allocate the heap memory for the data


		for (int i = 0; i < size; ++i)      // Populate the data
			data[i] = s[i];
	}
    // deep copy
	String(const String& args){
	    size = args.size;
	    data = new char[size];
	    for(int i=0;i<size;i++){
            data[i] = args.data[i];
	    }
	}
    ~String(){
       delete[] data;
    }
```

### Copy Elision

<p>
    Copy Elision is aimed to decrease the number of calls of copy constructors and destructors. Compilers will automatically do this for us.
</p>

### cast in class

<p>
    We can add a public method in the class definition to convert the class into the type you want.
</p>

```
  class Test{
   int i;
   public:
       Test(int d){
           i = d;
       }
       operator int() const{return i;} // add the 
};
```

<p>
   Above codes will cause compiler automatically convert the object with a view to making compilation success, and this is so-called implicit conversion. However, it will cause bugs sometimes. In order to avoid automatically conversion, we can add explicit in front of the method.

</p>

```
 class Test{
   int i;
   public:
       Test(int d){
           i = d;
       }
       explicit operator int() const{return i;} // add the method to make conversion 
};
```

### default member function and delete

<p>
    Sometimes we want to reduce the number of writing class methods like constructors and copy constructors, we can use "default". On the other hand, if we want to make a method uncallable, we can introduce "delete".
</p>

```
class Test {
public:
    Test(const Test&) = delete;                    // Deleted copy constructor
    Test& operator =(const Test&) = delete;        // Deleted assignment operator
public:
    Test() = default;                              // Synthesized default constructor
};

int main() {
	Test t1, t2;                                   // Use defaulted constructor
	Test t3(t1);                                   // Error: use of deleted function
	t2 = t1;                                       // Error: use of deleted function
}
```