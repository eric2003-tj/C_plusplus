# Template in C++

## template used in declare function

```
template<class T>
T Max(const T& a,const T& b){
  if(a > b){
     return a;
  }
  return b;
}
```

## template used in declare class

```
template<class T>
class Tmems{
  private:
      T data;
  public:
      Tmems(T new_data){
        data = new_data;
      }
      void get_data(){
        cout << data << endl;
      }
};
```

# Namespace

```
namespace abc{
  vector<int> vec{1,2,3};
  string str{"abcd"};
  class Yumn{
private:
    int x;
public:
    Yumn(int new_x){
      x = new_x;
    }
    void get_data(){
      cout << x << endl;
    }
  };
}
int main(){
   std::cout << abc::str << std::endl;
}
```

<p>
    If there are multiple namespaces and they both have class Yumn definition, and you decide to adopt the definition of namespace "def", we can use argument:"using def::Yumn;"
</p>