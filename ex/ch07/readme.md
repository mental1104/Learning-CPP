# Chapter 7 Classes  

## Exercises  

#### 7.1. Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).  

[Sales_data](../ch02/ex2_42_sales_data.h)  
[ex7_01.cpp](./ex7_01.cpp)  

#### 7.2. Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).

[ex7_02.h](./ex7_02_sales_data.h)  

#### 7.3. Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.  

[ex7_03.cpp](./ex7_03.cpp)

> Difference between 7.1 to 7.3:  

```cpp
void Sales_data::AddData(Sales_data data)
{
    if (bookNo != data.bookNo) return;
    units_sold += data.units_sold;
    revenue += data.revenue;
}
```

```cpp 
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

#### 7.4. Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.  

[ex7_04.h](./ex7_04.h)  

#### 7.5. Provide operations in your Person class to return the name and address. Should these functions be const? Explain your choice.

[ex7_05.h](./ex7_05.h)  

> Yes, a const following the parameter list indicates that this is a pointer to const. These functions my read but not write to the data members.  

#### 7.6. Define your own versions of the add, read, and print functions.  

[ex7_06_sales_data.h](./ex7_06_sales_data.h)  

#### 7.7. Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.  

[ex7_07.cpp](./ex7_07.cpp)  

#### 7.8. Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?  

> Since `read` will modify the internal data but not `print`.  

#### 7.9. Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).  

[ex7_09.h](./ex7_09.h)  

#### 7.10. What does the condition in the following if statement do?  

```cpp
if (read(read(cin, data1), data2))
``` 

> It firstly read data into data1 and then data2. Only when two input succeed can the condition become true.  

#### 7.11. Add constructors to your Sales_data class and write a program to use each of the constructors.  


[header](./ex7_11_sales_data.h)  
[implementation](./ex7_11_sales_data.cpp)  

#### 7.12. Move the definition of the Sales_data constructor that takes an istream into the body of the Sales_data class.  

[ex7_12.h](./ex7_12.h)  

#### 7.13. Rewrite the program from page 255 to use the istream constructor.  

[ex7_13.cpp](./ex7_13.cpp)  

#### 7.14. Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.  

```cpp
Sales_data(): units_sold(0) , revenue(0){}
```
[ex7_14_sales_data.h](./ex7_14_sales_data.h)  

#### 7.15. Add appropriate constructors to your Person class.  

[ex7_15.h](./ex7_15.h)  

#### 7.16. What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?  

> Those that wants to be called by outside clients should be declared public, and vice versa.  

#### 7.17. What, if any, are the differences between using class or struct?  

> The members of class are private without specifiers, and the members of struct are public without specifiers.  

#### 7.18. What is encapsulation? Why is it useful?  

> It provides methods to clients and hide the details that is no need for clients to know.  

+ User code cannot inadvertently corrupt the state of an encapsulation object.
+ The implementation of an encapsulated class can change over time without requiring changes in user-level code.  

#### 7.19. Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.  

> As follows:  

```cpp
class Person{
public:
    Person() = default;
    Person(const std::string& s):name(s){}
    Person(const std::string& n, const std::string & a):name(n),address(a){}
    
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
private:
    std::string name;
    std::string address;
};
```  

#### 7.20. When are friends useful? Discuss the pros and cons of using friends.  

> In chapter 12 we will use StrBlobPtr and ConstStrBlobPtr, for one class that wants to read another class's private data, friends are useful.  

Pros:

+ The useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
+ You can access all the nonpublic members conveniently.
sometimes, more readable to the users of class.

Cons:

+ lessens encapsulation and therefore maintainability.
+ code verbosity, declarations inside the class, outside the class.

#### 7.21. Update your Sales_data class to hide its implementation. The programs you’ve written to use Sales_data operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.  

> Now we're actually using class.  

[ex7_21_sales_data.h](./ex7_21_sales_data.h)   


#### 7.22. Update your Person class to hide its implementation.  

[ex7_22.h](./ex7_22.h)  

#### 7.23. Write your own version of the Screen class.  

[ex7_23.h](./ex7_23.h)

#### 7.24. Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.  

[ex7_24.h](./ex7_24.h)  

#### 7.25. Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?  

>  the class below which used only built-in type and strings can rely on the default version of copy and assignment. 

> In other word, we should write our own copy-constructor and assign-constructor when other self-created classes are in the class.  

#### 7.26. Define Sales_data::avg_price as an inline function.  

[ex7_26_sales_data.h](./ex7_26_sales_data.h)  
[ex7_26_sales_data.cpp](./ex7_26_sales_data.cpp)

#### 7.27. Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:  

```cpp
Screen myScreen(5, 5, ’X’);
myScreen.move(4,0).set(’#’).display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```  

[ex7_27.h](./ex7_27.h)  
[ex7_27.cpp](./ex7_27.cpp)  

#### 7.28. What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?

> It will duplicate it self to return a temporary copy instead of myScreen.  

#### 7.29. Revise your Screen class so that move, set, and display functions return Screen and check your prediction from the previous exercise.  

[ex7_29.h](./ex7_27.h)  
[ex7_29.cpp](./ex7_29.cpp)  

```
➜  ch07 git:(master) g++ ex7_27.cpp
➜  ch07 git:(master) ✗ ./a.out
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXX#XXXX
➜  ch07 git:(master) ✗ g++ ex7_29.cpp
➜  ch07 git:(master) ✗ ./a.out
XXXXXXXXXXXXXXXXXXXX#XXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

> `set()` actually modify the temporary copy returned by `move()`, not myScreen itself.  

#### 7.30. It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.  

Pros:

+ more explicit
+ less scope for misreading
+ can use the member function parameter which name is same as the member name.  

```cpp
void setAddr(const std::string &addr) {this->addr = addr;}
```

Cons:  

+ more to read
+ sometimes redundant

```cpp
std::string getAddr() const { return this->addr; } // unnecessary
```  

#### 7.31. Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.  

[ex7_31.h](./ex7_31.h)  

#### 7.32. Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.  

[ex7_32.h](./ex7_32.h)  

#### 7.33. What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.  

```cpp
pos Screen::size() const
{
return height * width;
}
```

> error: unknown type name 'pos' 

```cpp
Screen::pos Screen::size() const
{
    return height*width;
}
```  

#### 7.34. What would happen if we put the typedef of pos in the Screen class on page 285 as the last line in the class?

```
dummy_fcn(pos height)
           ^
Unknown type name 'pos'
```  

#### 7.35. Explain the following code, indicating which definition of Type or initVal is used for each use of those names. Say how you would fix any errors.  

```cpp
typedef string Type;
Type initVal();//string

class Exercise {
public:
    typedef double Type;
    Type setVal(Type);//double
    Type initVal();//double
private:
    int val;
};

Type Exercise::setVal(Type parm) {//first is `string`, second is `double`
    val = parm + initVal();     //// Exercise::initVal()
    return val;
}
```

> As follows.  

```cpp
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```  
> Exercise::initVal() should be defined.  

#### 7.36. The following initializer is in error. Identify and fix the problem.  

```cpp
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
```  

> fixed:  

```cpp
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int base, rem;
};
```    

#### 7.37. Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:

```cpp
Sales_data first_item(cin);//use Sales_data(std::istream &is) ; 
int main() {
    Sales_data next;//use Sales_data(std::string s = "");
    Sales_data last("9-999-99999-9");// use Sales_data(std::string s = "");
}
```

#### 7.38. We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.  

```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```  

#### 7.39. Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?

> No. For no parameter situation it would be ambiguous.   

#### 7.40. Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.  

(a) Book  
(d) Vehicle
(b) Date
(e) Object
(c) Employee
(f) Tree  

```cpp
class Book {
public:
    Book() = default;
    Book(unsigned no, std::string name, std::string author, std::string pubdate) : no_(no), name_(name), author_(author), pubdate_(pubdate) { }
    Book(std::istream &in) { in >> no_ >> name_ >> author_ >> pubdate_; }

private:
    unsigned no_;
    std::string name_;
    std::string author_;
    std::string pubdate_;
};
```  

#### 7.41. Rewrite your own version of the Sales_data class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.  

`g++ ex7_41_sales_data_test.cpp ex7_41_sales_data.cpp`  

[ex7_41_sales_data.h](./ex7_41_sales_data.h)  
[ex7_41_sales_data.cpp](./ex7_41_sales_data.cpp)  
[ex7_41_sales_data_test.cpp](./ex7_41_sales_data.cpp) 

```
1. default way: 
----------------
Sales_data(const std::string&, unsigned, double)
Sales_data()

2. use std::string as parameter: 
----------------
Sales_data(const std::string&, unsigned, double)
Sales_data(const std::string&)

3. complete parameters: 
----------------
Sales_data(const std::string&, unsigned, double)

4. use istream as parameter: 
----------------
Sales_data(const std::string&, unsigned, double)
Sales_data()
Sales_data(istream &is)
```

#### 7.42. For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.


```cpp
class Book {
public:
  Book(unsigned no, std::string name, std::string author, std::string pubdate):no_(no), name_(name), author_(author), pubdate_(pubdate) { }
  Book() : Book(0, "", "", "") { }
  Book(std::istream &in) : Book() { in >> no_ >> name_ >> author_ >> pubdate_; }

private:
  unsigned no_;
  std::string name_;
  std::string author_;
  std::string pubdate_;
};
```  

#### 7.43. Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. Define a class C that has a member of type NoDefault. Define the default constructor for C.  

[ex7_43.h](./ex7_43.h)  


#### 7.44. Is the following declaration legal? If not, why not?  

```cpp
vector<NoDefault> vec(10);
```  

[ex7_44.cpp](./ex7_44.cpp)

> Illegal, cause there are ten elements, each would be value initialized. But no default constructor for NoDefault type.

#### 7.45. What if we defined the vector in the previous execercise to hold objects of type C?  

> Correct, it will call the constructor taking a integer.  

#### 7.46. Which, if any, of the following statements are untrue? Why?  

(a) A class must provide at least one constructor.  

> Untrue, when there is no constructor, compiler will automatically generate a synthesized default constructor.    

(b) A default constructor is a constructor with an empty parameter list. 

> Untrue, A default constructor is a constructor that is used if no initializer is supplied.  

(c) If there are no meaningful default values for a class, the class should not pro-
vide a default constructor.  

> Untrue, like exercise 44, we should consider when the class reasonates with container.  

(d) If a class does not define a default constructor, the compiler generates one that
initializes each data member to the default value of its associated type.  

> Untrue, only if our class does not explicitly define **any constructors**, the compiler will implicitly define the default constructor for us.

#### 7.47. Explain whether the Sales_data constructor that takes a string should be explicit. What are the benefits of making the constructor explicit? What are the drawbacks?  

Pros:  

+ prevent the use of a constructor in a context that requires an implicit conversion.
+ we can define a constructor which is used only with the direct form of initialization.

Cons:  

+ meaningful only on constructors that can be called with a single argument.  

#### 7.48. Assuming the Sales_data constructors are not explicit, what operations happen during the following definitions?  

```cpp
string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");
```  

[ex7_48.cpp](./ex7_48.cpp)  

```
Sales_data(const std::string&, unsigned, double)
Sales_data(const std::string&)
Sales_data(const std::string&, unsigned, double)
Sales_data(const std::string&)
```  

#### 7.49. For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:  

```
(a) Sales_data &combine(Sales_data);//ok  
(b) Sales_data &combine(Sales_data&);  // [Error] no matching function for call to 'Sales_data::combine(std::string&)' (`std::string&` can not convert to `Sales_data` type.)  
(c) Sales_data &combine(const Sales_data&) const; //// The trailing const mark can't be put here, as it forbids any mutation on data members.   
```  

#### 7.50. Determine whether any of your Person class constructors should be explicit.  

[ex7_50.h](./ex7_50.h)  

```cpp
explicit Person(std::istream& is) { read(is, *this); }
```  

#### 7.51. Why do you think vector defines its single-argument constructor as explicit, but string does not?  

Such as a function like that:

```cpp
int getSize(const std::vector<int>&);
```  
if vector has not defined its single-argument constructor as explicit. we can use the function like:

```cpp
getSize(34);
```
What is this mean? It's very confused.

But the std::string is different. In ordinary, we use std::string to replace const char *(the C language). so when we call a function like that:

```cpp
void setYourName(std::string); // declaration.
setYourName("pezy"); // just fine.
```
it is very natural.  

#### 7.52. Using our first version of Sales_data from § 2.6.1 (p. 72), explain the following initialization. Identify and fix any problems.  

```cpp
Sales_data item = {"978-0590353403", 25, 15.99};
```  
From my machine It's fine...  

[ex7_52.cpp](./ex7_52.cpp)

```
➜  ch07 git:(master) ✗ g++ ex7_52.cpp
➜  ch07 git:(master) ✗ ./a.out
978-0590353403 25 15.99 0.6396
```  

#### 7.53. Define your own version of Debug.  

[ex7_53.h](./ex7_53.h)  

#### 7.54. Should the members of Debug that begin with set_ be declared asconstexpr? If not, why not?  

> It shouldn't, cause a constexpr function must contain exactly one return statement.  

#### 7.55. Is the Data class from § 7.5.5 (p. 298) a literal class? If not, why not? If so, explain why it is literal.  

> No. It can be verified by the following code.  

[ex7_55.cpp](./ex7_55.cpp)  

```cpp
#include <string>
#include <iostream>
#include <type_traits>

struct Data {
    int ival;
    std::string s;
};

int main()
{
    std::cout << std::boolalpha;
    std::cout << std::is_literal_type<Data>::value << std::endl;
    // output: false
}
```

```
➜  ch07 git:(master) ✗ g++ ex7_55.cpp
➜  ch07 git:(master) ✗ ./a.out
false
```

#### 7.56. What is a static class member? What are the advantages of static members? How do they differ from ordinary members?  

> (1) A class member that is associated with the class, rather than with individual objects of the class type.  

> (2) each object can no need to store a common data. And if the data is changed, each object can use the new value.  

> (3) a static data member can have incomplete type.  
> we can use a static member as a default argument.  

#### 7.57. Write your own version of the Account class.  

[ex7_57.h](./ex7_57.h)   

#### 7.58. Which, if any, of the following static data member declarations and definitions are errors? Explain why.  

```cpp
// example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```  

Problem:  
```cpp
static double rate = 6.5;
                ^
            rate should be a constant expression.

static vector<double> vec(vecSize);
                            ^
            we may not specify an in-class initializer inside parentheses.
```  

Fixed:  

```cpp 
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```