# String

## About std::string
<p>
  In C++, std::string is composed of two parts:
    <ol>
      <li> A pointer points to the array of char</li>
      <li> Length of the string</li>
    </ol>
</p>

```
  class string{
    private:
      int length;
      char *str;
  }
```

## Operations of std::string

<ol>
    <li>addition</li>
    <li>comparison</li>
</ol>

```
   1. 
      string str{"hello"};
      string str2{" world"};
      str += str2;
   2.
      string str1{"jjjjj"};
      string str2{"lllll"};
      cout << boolalpha << (str1 > str2);  //remember to include <iomanip>
 ```
 
 ## constructor
 <ol>
    <li> string s1{"hello"};</li>
    <li> string triplex(3, 'x'); ---"xxx"</li> 
</ol>
 
 ## methods 
 
 1. substr
 <ul>
    <li>str.substr(6) -- get str from index6 to index(str.length-1)</li> 
    <li>str.substr(6,2) -- get str[6] and str[7]</li> 
</ul>

 2. c_str()
<p>
   &ensp;&ensp;The method is to translate C++ string to C string,similar to str.data()   
</p>

3. find()
   <p>
      General find():
   </p>

   ```
   string str{"Hello world"};
   if(str.find('o') != string::npos){
      cout << str.find('o') << endl; //print 4
   }
   if(str.find("or") != string::npos){
      cout << str.find("or") << endl; //print 7
   }
   if(str.find('O') != string::npos){
      cout << str.find('O') << endl;
   }
   if(str.rfind('o') != string::npos){
      cout << str.rfind('o') << endl; //print 4
   }
   if(str.rfind("or") != string::npos){
      cout << str.rfind("or") << endl; //print 7
   }
   if(str.rfind('O') != string::npos){
      cout << str.rfind('O') << endl;
   }
   ```
   
   <p>
      Special use:
   </p>
   
   ```
   string vowels {"aeiou"};
   cout << str.find_first_of(vowels) << endl; //print 1
   cout << str.find_last_of(vowels) << endl; //print7
   cout << str.find_first_not_of(vowels) << endl; //print0
   cout << str.find_last_not_of(vowels) << endl; //print9
   ```
 4. append()
     ```
     string hello{"hello"};
     hello.append(" world"); //hello world
     string hello2 {"Hello"};
     hello2.append("wow!!!!", 3, 2); //Hello!!
     ```
 5. insert()
     <p>
       normal use
     </p>
 
     ```
     string str{ "for" };
     str.insert(2, "lde"); //folder
     string str2{ "care" };
     string str3{ "omp" };
     str2.insert(1, str3); // compare
     ```
     
     <p>
       special use : case 1
     </p>
     
     ```
     string str { "xx" };
     string str2{ "trombone" };
     str.insert(1, str2, 4, 2); //xbox
     ```
     
     <p>
       special use : case 2
     </p>
     
     ```
     string str{ "word" };
     auto last = str.end() - 1;
     str.insert(last, 'l'); //world
     string str2{ "ski" };
     auto last2 = str2.end();
     str2.insert(last2, 2, 'l'); //skill
     ```
  6. erase()
     ```
      string str{"hello"};
      str.erase(1,2); // hlo
      cout << str << endl;
      str.assign("hello");
      str.erase(str.begin(),str.begin()+2); //llo
      cout << str << endl;
     ```
 7. replace()
    ```
    string str{"hello"};
    str.replace(1,3,"lllllll"); // replace three elements
    cout << str << endl;
    str.assign("hello");
    str.replace(str.begin()+1,str.end()-2,"llllllll");
    cout << str << endl;
    ```
 8. assign()
    ```
    string str1{"jjj"};
    str1.assign("lll");
    cout << str1 <<endl; //lll
    ```
 9. stoi()
    <p>
    we can use the method(it can be global func) to convert string into integer, moreover ,it can be used to convert string representing different base into decimal
</p>


```    
    int a = stoi("2a",nullptr,16);
    cout << a << endl;
```

10. swap()
   <p>
    &ensp;&ensp;The method(or global func) can be used to swap the data in the string   by changing its pointer's &ensp;&ensp;value
   </p>