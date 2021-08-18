# BASICS  

## Chapter 1 Function Templates  

### 1.1 A First Look at Function Templates  

[max1.hpp](./max1.hpp)  
[max1.cpp](./max1.cpp)  

`g++ max1.cpp`  
`./a.out`  

```
max(7,i)  42
max(f1,f2):   3.4
max(s1, s2):  mathematics
```  

### 1.5 Overloading Function Templates

[max3ref.cpp](./max3ref.cpp)  

`g++ max3ref.cpp`  
`./a.out`  

```
max3ref.cpp: In instantiation of ‘const T& max(const T&, const T&, const T&) [with T = const char*]’:
max3ref.cpp:25:31:   required from here
max3ref.cpp:16:15: warning: returning reference to temporary [-Wreturn-local-addr]
   16 |     return max(max(a,b), c);
      |            ~~~^~~~~~~~~~~~~

➜  basics git:(master) ✗ ./a.out
[1]    4044 segmentation fault (core dumped)  ./a.out
```



