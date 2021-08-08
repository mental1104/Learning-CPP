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

#### 6.16 The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function:  

```cpp
bool is_empty(string& s) { return s.empty(); }
```  

> Since this function doesn't change the argument,"const" shoud be added before string&s,otherwise this function is misleading and can't be used with const string or in a const function.  

#### 6.17 Write a function to determine whether a string contains any capital letters. Write a function to change a string to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

[ex6_17.cpp](./ex6_17.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_17.cpp
➜  ch06 git:(master) ✗ ./a.out
1
you are going down.
```  

#### 6.18 Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.  

(a) A function named compare that returns a bool and has two parameters that
are references to a class named matrix.  

```cpp
bool compare(const Matrix& a, const Matrix& b);
```
(b) A function named change_val that returns a vector<int> iterator and
takes two parameters: One is an int and the other is an iterator for a vector<int>.  

```cpp
vector<int>::iterator change_val(int a, vector<int>::iterator iter);
```  

#### 6.19 Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.  

```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```

(a) calc(23.4, 55.1);   
> Illegal. Only one parameter.  

(b) count("abcda", ’a’);  
> Legal.  

(c) calc(66);  
> Legal.  

(d) sum(vec.begin(), vec.end(), 3.8);  
> Legal.  

#### 6.20 When should reference parameters be references to const? What happens if we make a parameter a plain reference when it could be a reference to const?  

> If we can use const, just use it. If we make a parameter a plain reference when it could be a reference to const, the reference value maybe changed.

#### 6.21 Write a function that takes an int and a pointer to an int and returns the larger of the int value or the value to which the pointer points. What type should you use for the pointer?  

[ex6_21.cpp](./ex6_21.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_21.cpp
➜  ch06 git:(master) ✗ ./a.out
101
```  

#### 6.22 Write a function to swap two int pointers.  

[ex6_22.cpp](./ex6_22.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_22.cpp
➜  ch06 git:(master) ✗ ./a.out
40 50
```  

#### 6.23 Write your own versions of each of the print functions presented in this section. Call each of these functions to print i and j defined as follows:  

```cpp
int i = 0, j[2] = {0, 1};
```

```
➜  ch06 git:(master) ✗ g++ ex6_23.cpp
➜  ch06 git:(master) ✗ ./a.out
devil
0 1 
0
0 1 
```

#### 6.24 Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.  

```cpp
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

> n this question, const int ia[10] is actually same as const int*, and the size of the array is irrelevant. we can pass const int ia[3] or const int ia[255], there are no differences. If we want to pass an array which size is ten, we should use reference like that:  
```cpp
void print10(const int (&ia)[10]) { /*...*/ }
```
#### 6.25 Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting string.  

[ex6_25.cpp](./ex6_25.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_25.cpp
➜  ch06 git:(master) ✗ ./a.out blue espeon will never fall
blue espeon will never fall 
```  

#### 6.26 Write a program that accepts the options presented in this section. Print the values of the arguments passed to main.  

> Same as [ex6_25.cpp](./ex6_25.cpp).  

#### 6.27 Write a function that takes an initializer_list<int> and produces the sum of the elements in the list.  

[ex6+27.cpp](./ex6_27.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_27.cpp
➜  ch06 git:(master) ✗ ./a.out
55
```

#### 6.28 In the second version of error_msg that has an ErrCode parameter, what is the type of elem in the for loop?  

> const string&  

#### 6.29 When you use an initializer_list in a range for would you ever use a reference as the loop control variable? If so, why? If not, why not?  

> Depends on the type of elements of initializer_list. When the type is PODType, reference is unnecessary. Because POD is cheap to copy(such as int). Otherwise, Using reference(const) is the better choice.  

#### 6.30 Compile the version of str_subrange as presented on page 223 to see what your compiler does with the indicated errors.  

```cpp
// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
        return str1 == str2;
        // ok: == returns bool
    // find the size of the smaller string ; conditional operator, see § 4.7 (p. 151)
    auto size = (str1.size() < str2.size())? str1.size() : str2.size();
    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i])
            return; // error #1: no return value; compiler should detect this error
    }
    // error #2: control might flow off the end of the function without a return
    // the compiler might not detect this error
}
```

> Non-void function 'str_subrange' should return a value. // error #1  
> Control may reach end of non-void function. // error #2  

#### 6.31 When is it valid to return a reference? A reference to const?  

> when you can find the preexisted object that the reference refered.

#### 6.32 Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

```cpp
int &get(int *arry, int index) { return arry[index]; }
int main() {
    int ia[10];
    for (int i = 0; i != 10; ++i)
        get(ia, i) = i;
}
```

> legal, it gave the values (0 ~ 9) to array ia.  

#### 6.33 Write a recursive function to print the contents of a vector.  

[ex6_33.cpp](./ex6_33.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_33.cpp
➜  ch06 git:(master) ✗ ./a.out
5 5 5 5 5 5 5 5 5 5 
```  

#### 6.34 What would happen if the stopping condition in factorial were  

```cpp
if (val != 0)
```  

> When the recursion termination condition becomes var != 0, two situations can happen : case 1 : If the argument is positive, recursion stops at 0. This is exactly what @shbling pointed out. case 2 : if the argument is negative, recursion would never stop. As a result,a stack overflow would occur.  

#### 6.35 In the call to factorial, why did we pass val - 1 rather than val--?  

> the recursive function will always use val as the parameter. a recursion loop would happen.  

#### 6.36 Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.  

```cpp
string (&func(string (&arrStr)[10]))[10];
```  

#### 6.37 Write three additional declarations for the function in the previous exercise. One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?  

```cpp
using ArrT = string[10];
ArrT& func1(ArrT& arr);

auto func2(ArrT& arr) -> string(&)[10];

string arrS[10];
decltype(arrS)& func3(ArrT& arr);
```  

#### 6.38 Revise the arrPtr function on to return a reference to the array.  

```cpp
decltype(odd)& arrPtr(int i){
    return (i%2)? &odd : &even;
}

auto arrPtr(int i) -> int &[10];
```

#### 6.39 Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

```cpp
(a) int calc(int, int);
int calc(const int, const int);
//legal  
(b) int get();
double get();
//illegal
(c) int *reset(int *);
double *reset(double *);
//legal  
```

#### 6.40 Which, if either, of the following declarations are errors? Why?  

```cpp
(a) int ff(int a, int b = 0, int c = 0);//legal
(b) char *init(int ht = 24, int wd, char bckgrnd);//illegal
```  

#### 6.41 Which, if any, of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer’s intent? Why?  

```cpp
char *init(int ht, int wd = 80, char bckgrnd = ’ ’);
(a) init();//illegal
(b) init(24,10);//legal, match
(c) init(14, ’*’);//legal but not match, wd will be set as `*`  
```  

#### 6.42 Give the second parameter of make_plural (§ 6.3.2, p. 224) a default argument of ’s’. Test your program by printing singular and plural versions of the words success and failure.

[ex6_42.cpp](./ex6_42.cpp)  

```
➜  ch06 git:(master) ✗ g++ ex6_42.cpp
➜  ch06 git:(master) ✗ ./a.out
singual: success failure
plural : successes failures
```


#### 6.43 Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.  

```cpp
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);
```  

> Both two should put in a header. (a) is an inline function. (b) is the declaration of useful function. we always put them in the header.


#### 6.44 Rewrite the isShorter function from § 6.2.2 (p. 211) to be inline.  

```cpp
inline bool isShorter(const string&a, const string& b){
    return a.size()<b.size();
}
```  

#### 6.45 Review the programs you’ve written for the earlier exercises and decide whether they should be defined as inline. If so, do so. If not, explain why they should not be inline.  

> For example, the function arrPtr in Exercise 6.38 and make_plural in Exercise 6.42 should be defined as inline. But the function func in Exercise 6.4 shouldn't. Cause it just being call once and too many codes in the function.  

#### 6.46 Would it be possible to define isShorter as a constexpr? If so, do so. If not, explain why not.  

No.

> A constexpr function is defined like any other function but must meet certain restrictions: The **return type** and **the type of each parameter** in a must be a literal type

But `std::string`(parameter of `isShorter`) is not a literal type.

more discusses: [#22](https://github.com/ReadingLab/Discussion-for-Cpp/issues/22)  

#### 6.47 Revise the program you wrote in the exercises in § 6.3.2 (p. 228) that used recursion to print the contents of a vector to conditionally print information about its execution. For example, you might print the size of the vector on each call. Compile and run the program with debugging turned on and again with it turned off.  

[ex6_47.cpp](./ex6_47.cpp)    

```
➜  ch06 git:(master) ✗ g++ -D NDEBUG ex6_47.cpp
➜  ch06 git:(master) ✗ ./a.out
1 2 3 4 5 6 7 8 9 
```  

#### 6.48 Explain what this loop does and whether it is a good use of assert:  

```cpp
string s;
while (cin >> s && s != sought) { }
assert(cin);
```  

> This loop let user input a word all the way until the word is sought.

#### 6.49 What is a candidate function? What is a viable function?  

candidate function:

> Set of functions that are considered when resolving a function call. (all the functions with the name used in the call for which a declaration is in scope at the time of the call.)

viable function:

> Subset of the candidate functions that could match a given call. It have the same number of parameters as arguments to the call, and each argument type can be converted to the corresponding parameter type.

#### 6.50 Given the declarations for f from page 242, list the viable functions, if any for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.

(a) f(2.56, 42)  
> illegal. 2.56 match the double, but 42 match the int.  

(b) f(42)  
> match void f(int).  

(c) f(42, 0)
> match void f(int, int).  

(d) f(2.56, 3.14)
> match void f(double, double = 3.14).  

#### 6.51 Write all four versions of f. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.  

[ex6_51.cpp](./ex6_51.cpp)  

#### 6.52 Given the following declarations,  

```cpp
void manip(int, int);
double dobj;
```  
what is the rank (§ 6.6.1, p. 245) of each conversion in the following calls?  

```cpp
(a) manip(’a’, ’z’);  
// match through a promotion  
(b) manip(55.4, dobj);
// Arithmetic type conversion
```  

#### 6.53 Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.  

(a)  
```
int calc(int&, int&); // calls lookup(int&)
int calc(const int&, const int&); // calls lookup(const int&)
```  

(b)  
```
int calc(char*, char*); // calls lookup(char*)
int calc(const char*, const char*); //calls lookup(const char *)  
```  

(c)  

> illegal.  

#### 6.54 Write a declaration for a function that takes two int parameters and returns an int, and declare a vector whose elements have this function pointer type.  

```cpp 
int fun(int, int);
vector<decltype(fun)*> 
```  

#### 6.55 Write four functions that add, subtract, multiply, and divide two int values. Store pointers to these functions in your vector from the previous exercise.  

[ex6_55.cpp](./ex6_55.cpp)  

#### 6.56 Call each element in the vector and print their result.  

```
➜  ch06 git:(master) ✗ g++ ex6_55.cpp
➜  ch06 git:(master) ✗ ./a.out
12
8
20
5
```

