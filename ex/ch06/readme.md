# Chapter 6 Functions  

#### 6.1 What is the difference between a parameter and an argument?  

+ Parameters: Local variable declared inside the function parameter list. they are initialized by the arguments provided in the each function call.

+ Arguments: Values supplied in a function call that are used to initialize the function's parameters.  

#### 6.2 Indicate which of the following functions are in error and why. Suggest how you might correct the problems.  

```
(a) int f() {
string s;
// . . .
return s;
}
(b) f2(int i) { /* . . . */ }
(c) int calc(int v1, int v1) /* . . . */ }
(d) double square(double x) return x * x;
```
FIXED:  
```
(a) string f() {
string s;
// . . .
return s;
} //incorrect return type
(b) void f2(int i) { /* . . . */ }//lost return type
(c) int calc(int v1, int v2) /* . . . */ }//duplicate parameters
(d) double square(double x) { return x * x; }//lost block  
```

#### 6.3 Write and test your own version of fact.  

```cpp
#include <iostream>

int fact(int val)
{
    if (val == 0 || val == 1) return 1;
    else return val * fact(val-1);
}

int main()
{
    int j = fact(5);  // j equals 120, i.e., the result of fact(5)
    std::cout << "5! is " << j << std::endl;
    return 0;
}
```  

```
➜  ch06 git:(master) ✗ g++ ex6_03.cpp
➜  ch06 git:(master) ✗ ./a.out
5! is 120
```  

#### 6.4 Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from main.  

[ex6_04.cpp](./ex6_04.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_04.cpp
➜  ch06 git:(master) ✗ ./a.out
10
3628800
```  

#### 6.5 Write a function to return the absolute value of its argument.  

[ex6_05.cpp](./ex6_05.cpp)  

```cpp
#include<iostream>

int _abs(int a){
    if(a<0)
        a=~a+1;
    return a;
}
```

#### 6.6 Explain the differences between a parameter, a local variable, and a local static variable. Give an example of a function in which each might be useful.  

+ local variable: Variables defined inside a block;

+ parameter: Local variables declared inside the function parameter list

+ local static variable: local static variable（object） is initialized before the first time execution passes through the object’s definition.Local statics are not destroyed when a function ends; they are destroyed when the program terminates.  

```cpp
// example
size_t count_add(int n)       // n is a parameter.
{
    static size_t ctr = 0;    // ctr is a static variable.
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)  // i is a local variable.
      cout << count_add(i) << endl;

    return 0;
}
```  

#### 6.7 Write a function that returns 0 when it is first called and then generates numbers in sequence each time it is called again.  

[ex6_07.cpp](./ex6_07.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_07.cpp
➜  ch06 git:(master) ✗ ./a.out
0
1
2
3
4
5
6
7
8
9
```

#### 6.8 Write a header file named Chapter6.h that contains declarations for the functions you wrote for the exercises in § 6.1 (p. 205).

[Chapter6.h](./Chapter6.h)  

#### 6.9 Write your own versions of the fact.cc and factMain.cc files. These files should include your Chapter6.h from the exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

[fact.cc](./fact.cc)  
[factMain.cc](./factMain.cc)  

```
➜  ch06 git:(master) ✗ g++ factMain.cc fact.cc ex6_05.cpp
➜  ch06 git:(master) ✗ ./a.out
5! is 120
input a number: 5
120
9
```  

#### 6.10 Using pointers, write a function to swap the values of two ints. Test the function by calling it and printing the swapped values.  

[ex6_10.cpp](./ex6_10.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_10.cpp
➜  ch06 git:(master) ✗ ./a.out
100 50
```  

#### 6.11 Write and test your own version of reset that takes a reference.  

[ex6_11.cpp](./ex6_11.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_11.cpp
➜  ch06 git:(master) ✗ ./a.out
0
```  

#### 6.12 Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210) to use references instead of pointers to swap the value of two ints. Which version do you think would be easier to use and why?

[ex6_12.cpp](./ex6_12.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_12.cpp
➜  ch06 git:(master) ✗ ./a.out
100 50
```

> Though I prefer pointer, I have to admit that reference is easy to use and understand.  

#### 6.13 Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&). 

> f(T) will copy a temporary value into the parameter.  

> f(T&) will only allow the argument itself into parameter.  

#### 6.14 Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.  

> should be: 

```cpp 
void reset(int &i)
{
        i = 0;
}
```  

> shouldn't be:  
```cpp
void print(std::vector<int>::iterator begin, std::vector<int>::iterator end)//it affects the behavior outside the block.  
{
        for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
                std::cout << *iter << std::endl;
}
```

#### 6.15 Explain the rationale for the type of each of find_char’s parameters In particular, why is s a reference to const but occurs is a plain reference? Why are these parameters references, but the char parameter c is not? What would happen if we made s a plain reference? What if we made occurs a reference to const?  

```cpp
// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c,
string::size_type &occurs)
{
    auto ret = s.size();
    // position of the first occurrence, if any
    occurs = 0;
    // set the occurrence count parameter
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            // remember the first occurrence of c
            ++occurs;
            // increment the occurrence count
        }
    }
    return ret;
    // count is returned implicitly in occurs
}
```

why is s a reference to const but occurs is a plain reference? 
> We should ensure that s won't affect the behavior outside the function.  

Why are these parameters references, but the char parameter c is not?  
> Copy by value is more effective with a value of 1 byte, however when transferred as reference or pointer it will cost 8 bytes. Without reference to char is more memory-efficent.  


What would happen if we made s a plain reference? 
> Dangerous, since the function would modify `s` without casting any error message.    

What if we made occurs a reference to const?  
> Then `occur` won't change, which doesn't met with our requirement.  



