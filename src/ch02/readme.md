# Chapter 2 Variables and Basic Types  

## Exercise  

#### 2.1. What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?

```
long >= int  
long long >= long  
int >= short  

unsigned > 0  
signed -x ~ +x  

float  1 8 23  ->32 bit  
double 1 12 51 ->64 bit
```  

#### 2.2. To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

```
Interest rate: double  
Principal :    double  
Payment   :    double
```

#### 2.3. What output will the following code produce?  

```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```  

```
32    
4294967264
32  
-32  
0  
0  
```  

#### 2.4. Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.  

[ex2_04.cpp](./ex2_04.cpp)  

```
➜  ch02 git:(master) ✗ g++ ex2_4.cpp
➜  ch02 git:(master) ✗ ./a.out
32
4294967264
32
-32
0
0
```  

#### 2.5. Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:  

(a) ’a’, L’a’, "a", L"a"  
> haracter literal, wide character literal, string literal, wide string literal.    

(b) 10, 10u, 10L, 10uL, 012, 0xC  
> integer, unsigned, long, unsigned long, octal, hex.   

(c) 3.14, 3.14f, 3.14L   
> double, float, long double    

(d) 10, 10u, 10., 10e-2     
> decimal, unsigned decimal, double, double.  

#### 2.6. What, if any, are the differences between the following definitions:  

```
int month = 9, day = 7;
int month = 09, day = 07;
```  

> The first line here possesses a decimal literal.  
> The second line possesses a octal literal, and 09 is invalid.    

#### 2.7. What values do these literals represent? What type does each have?   

(a) "Who goes with F\145rgus?\012"  
> \145 == 'e'  \012 == '\n'   

(b) 3.14e1L  
> 3.14e1L == 31.4, long double    

(c) 1024f
> ~~1024f == 1024.0, float~~  
ERROR: The suffix f is valid only with floating point literals     

(d) 3.14L  
> 3.14L == 3.14, long double   

#### 2.8. Using escape sequences, write a program to print 2M followed by a newline. Modify the program to print 2, then a tab, then an M, followed by a newline.

[ex2_08.cpp](./ex2_08.cpp)  

```
➜  ch02 git:(master) ✗ g++ ex2_08.cpp
➜  ch02 git:(master) ✗ ./a.out
2M
2       M
```

#### 2.9. Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.  

(a) std::cin >> int input_value;  
> error.  
```cpp
int input_value = 0;
std::cin >> input_value;
```
(b) int i = { 3.14 };  
> error.  
```cpp
double i = { 3.14 };
```
(c) double salary = wage = 9999.99;   
> if declared 'wage' before, it's right.  
```cpp
double wage;
double salary = wage = 9999.99;
```
(d) int i = 3.14;  
> Ok: but value will be truncated.
```cpp
double i = 3.14;
```  

#### 2.10. What are the initial values, if any, of each of the following variables?  

```cpp
std::string global_str;//empty string
int global_int;//0
int main()
{
    int local_int;//undefined
    std::string local_str;//empty string
}
```  

#### 2.11. Explain whether each of the following is a declaration or a definition:  

(a) extern int ix = 1024;  
> Definition  

(b) int iy;  
> Definition

(c) extern int iz;  
> Declaration     

#### 2.12. Which, if any, of the following names are invalid?  

(a) int double = 3.14;  
> Invalid.  

(b) int _;  
> valid.

(c) int catch-22;
> Inalid.  

(d) int 1_or_2 = 1;  
> Invalid.   

(e) double Double = 3.14;  
> Valid.  

#### 2.13. What is the value of j in the following program?  

```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```  

> 100  

#### 2.14. Is the following program legal? If so, what values are printed?  

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```  
> Legal. 100 45  

#### 2.15. Which of the following definitions, if any, are invalid? Why?  

(a) int ival = 1.01;  
> Valid.  

(b) int &rval1 = 1.01;  
> Invalid. Reference and literal don't mix.  

(c) int &rval2 = ival;  
> Valid.  

(d) int &rval3;  
> Invalid. Without initializing.  

#### 2.16. Which, if any, of the following assignments are invalid? If they are valid, explain what they do.  
```cpp
int i = 0, &r1 = i; 
double d = 0, &r2 = d;
```
(a) r2 = 3.14159;  
> Valid.  d = 3.14159  

(b) r2 = r1;  
> Valid. int converts to double  

(c) i = r2;   
> Valid. Value will be truncated.  

(d) r1 = d;  
> Valid. Value will be truncated.  

#### 2.17. What does the following code print?  

```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```  
> 10 10  

#### 2.18. Write code to change the value of a pointer. Write code to change the value to which the pointer points.

[ex2_18.cpp](./ex2_18.cpp)  

#### 2.19. Explain the key differences between pointers and references.  

> reference is not a object, and it's just an another name of other object, which can't bind another object anymore.  

> pointer is a object, and it can point to an object which possesses a same type at any time.   

#### 2.20. What does the following program do?  

```cpp
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

> i's value change to 42 * 42.  

#### 2.21. Explain each of the following definitions. Indicate whether any are illegal and, if so, why.  

int i = 0;
(a) double* dp = &i;  
> illegal, cannot initialize a variable of type double * with an rvalue of type int *.   

(b) int *ip = i; 
> illegal, cannot initialize a variable of type int * with an lvalue of type int.  

(c) int *p = &i;  
> legal.  

#### 2.22. Assuming p is a pointer to int, explain the following code:  

if (p) // ...  
> p = true when p point to some value. 

if (*p) // ...
> the value of p is 0 so that it's false, and true if not.    

#### 2.23. Given a pointer p, can you determine whether p points to a valid object? If so, how? If not, why not?  
> No.  

#### 2.24. Why is the initialization of p legal but that of lp illegal?  

int i = 42;   
void *p = &i;  
long *lp = &i;  

> (void *) is a special pointer type that can hold the address of any object.   

#### 2.25. Determine the types and values of each of the following variables.  

(a) int* ip, i, &r = i;  
> ip is a pointer to int, i is an int, r is a reference to int i.

(b) int i, *ip = 0;  
> ip is a valid, null pointer, and i is an int.  

(c) int* ip, ip2;  
> ip is a pointer to int, and ip2 is an int.  

#### 2.26. Which of the following are legal? For those that are illegal, explain why.  

(a) const int buf;  
> Illegal, it should be initialized.  

(b) int cnt = 0;  
> Legal.  

(c) const int sz = cnt; 
> Legal.  

(d) ++cnt; ++sz;  
> The latter is illegal.  

#### 2.27. Which of the following initializations are legal? Explain why.  

```cpp
int i = -1, &r = 0;         // illegal, r must refer to an object.
int *const p2 = &i2;        // legal.
const int i = -1, &r = 0;   // legal.
const int *const p3 = &i2;  // legal.
const int *p1 = &i2;        // legal
const int &const r2;        // illegal, r2 is a reference that cannot be const.
const int i2 = i, &r = i;   // legal.
```

#### 2.28. Explain the following definitions. Identify any that are illegal.  

```cpp
int i, *const cp;       // illegal, cp must initialize.
const int ic, &r = ic;  // illegal, ic must initialize.
int *p1, *const p2;     // illegal, p2 must initialize.
const int *const p3;    // illegal, p3 must initialize.
const int *p;           // legal. a pointer to const int.
```  

#### 2.29. Uing the variables in the previous exercise, which of the following assignments are legal? Explain why.  

```cpp
i = ic;     // legal.
p1 = p3;    // illegal. p3 is a pointer to const int.
p1 = &ic;   // illegal. ic is a const int.
p3 = &ic;   // illegal. p3 is a const pointer.
p2 = p1;    // illegal. p2 is a const pointer.
ic = *p3;   // illegal. ic is a const int.
```  

#### 2.30. For each of the following declarations indicate whether the object being declared has top-level or low-level const.  

```cpp
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```  

+ v2 is top-level const, p2 is low-level const.
+ p3: right-most const is top-level, left-most is low-level.
+ r2 is low-level const.

#### 2.31. Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.  

```cpp
r1 = v2; // legal, top-level const in v2 is ignored.
p1 = p2; // illegal, p2 has a low-level const but p1 doesn't.
p2 = p1; // legal, we can convert int* to const int*.
p1 = p3; // illegal, p3 has a low-level const but p1 doesn't.
p2 = p3; // legal, p2 has the same low-level const qualification as p3.
```

#### 2.32. Is the following code legal or not? If not, how might you make it legal?  

```cpp
int null = 0, *p = null;
```

FIXED:  
```cpp
int null = 0, *p = NULL;
```
Or (Prefered):  
```cpp
int null = 0, *p = nullptr;
```  

#### 2.33. Using the variable definitions from this section, determine what happens in each of these assignments:  

```cpp
int i = 0, &r = i;
auto a = r; // a is an int ( r is an alias for i , which has type int )
const int ci = i, &cr = ci;
auto b = ci; // b is an int (top-level const in ci is dropped)
auto c = cr; // c is an int ( cr is an alias for ci whose const is top-level)
auto d = &i; // d is an int* ( & of an int object is int* )
auto e = &ci; // e is const int* ( & of a const object is low-level const )  
const auto f = ci;// deduced type of ci is int ; f has type const int  
auto &g = ci;// g is a const int& that is bound to ci
auto &h = 42;// error: we can’t bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal
auto k = ci, &l = i;// k is int ; l is int&
auto &m = ci, *p = &ci; // m is a const int& ; p is a pointer to const int
auto &n = i, *p2 = &ci;// error: type deduced from i is int ; type deduced from &ci is const int
```

```cpp
a = 42; // set 42 to int a.
b = 42; // set 42 to int b.
c = 42; // set 42 to int c.
d = 42; // ERROR, d is an int *. correct: *d = 42;
e = 42; // ERROR, e is an const int *. correct: e = &c;
g = 42; // ERROR, g is a const int& that is bound to ci.
```

#### 2.34. Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you can convince yourself you know what led you to the wrong conclusion.

[ex2_34.cpp](./ex2_34.cpp)  

#### 2.35. Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.  

```cpp
const int i = 42;
auto j = i; //int 
const auto &k = i;//const int& 
auto *p = &i;// const int* 
const auto j2 = i, &k2 = i;//const int, const int&  
```  

[ex2_35.cpp](./ex2_35.cpp)  

#### 2.36. In the following code, determine the type of each variable and the value each variable has when the code finishes:  

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```  
> c is an int, d is a reference of a. all their value are 4.  

#### 2.37. Assignment is an example of an expression that yields a reference type. The type is a reference to the type of the left-hand operand. That is, if i is an int, then the type of the expression i = x is int&. Using that knowledge, determine the type and value of each variable in this code:  

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```  

> c is an int, d is a reference of int.  
> the value: a = 3, b = 4, c = 3, d = 3  

#### 2.38. Describe the differences in type deduction between decltype and auto. Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.

> The way decltype handles top-level const and references differs subtly from the way auto does. Another important difference between decltype and auto is that the deduction done by decltype depends on the form of its given expression.  

```cpp
int i = 0, &r = i;
// same
auto a = i;
decltype(i) b = i;
// different
auto c = r;
decltype(r) d = r;
```  

#### 2.39. Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.  

```cpp
struct Foo { /* empty */ } // Note: no semicolon
int main()
{
return 0;
}
```

```
error: expected ‘;’ after struct definition
 struct Foo{}
             ^
             ;
```

#### 2.40. Write your own version of the Sales_data class.  

[ex2_40.h](./ex2_40_sales_data.h)  

#### 2.41. Use your Sales_data class to rewrite the exercises in § 1.5.1 (p. 22), § 1.5.2 (p. 24), and § 1.6 (p. 25). For now, you should define your Sales_data class in the same file as your main function.  

[ex2_41_1.cpp](./ex2_41_1.cpp)  
[ex2_41_2.cpp](./ex2_41_2.cpp)  
[ex2_41_3.cpp](./ex2_41_3.cpp)   

#### 2.42. Write your own version of the Sales_data.h header and use it to rewrite the exercise from § 2.6.2 (p. 76).  

[ex2_42_sales_data.h](./ex2_42_sales_data.h)  
[ex2_42_1.cpp](./ex2_42_1.cpp)  
[ex2_42_2.cpp](./ex2_42_2.cpp)  
[ex2_42_3.cpp](./ex2_42_3.cpp)

 






