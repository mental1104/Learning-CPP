# Chapter 7 Classes  

## Exercises  

### 1. Write a version of the transaction-processing program from § 1.6 (p. 24) using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).  

[Sales_data](../ch02/ex2_42_sales_data.h)  
[ex7_01.cpp](./ex7_01.cpp)  

### 2. Add the combine and isbn members to the Sales_data class you wrote for the exercises in § 2.6.2 (p. 76).

[ex7_02.h](./ex7_02_sales_data.h)  

### 3. Revise your transaction-processing program from § 7.1.1 (p. 256) to use these members.  

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

### 4. Write a class named Person that represents the name and address of a person. Use a string to hold each of these elements. Subsequent exercises will incrementally add features to this class.  

[ex7_04.h](./ex7_04.h)  

### 5. Provide operations in your Person class to return the name and address. Should these functions be const? Explain your choice.

[ex7_05.h](./ex7_05.h)  

> Yes, a const following the parameter list indicates that this is a pointer to const. These functions my read but not write to the data members.  

### 6. Define your own versions of the add, read, and print functions.  

[ex7_06_sales_data.h](./ex7_06_sales_data.h)  

### 7. Rewrite the transaction-processing program you wrote for the exercises in § 7.1.2 (p. 260) to use these new functions.  

[ex7_07.cpp](./ex7_07.cpp)  

### 8. Why does read define its Sales_data parameter as a plain reference and print define its parameter as a reference to const?  

> Since `read` will modify the internal data but not `print`.  

### 9. Add operations to read and print Person objects to the code you wrote for the exercises in § 7.1.2 (p. 260).  

[ex7_09.h](./ex7_09.h)  

### 10. What does the condition in the following if statement do?  

```cpp
if (read(read(cin, data1), data2))
``` 

> It firstly read data into data1 and then data2. Only when two input succeed can the condition become true.  

### 11. Add constructors to your Sales_data class and write a program to use each of the constructors.  


[header](./ex7_11_sales_data.h)  
[implementation](./ex7_11_sales_data.cpp)  

### 12. Move the definition of the Sales_data constructor that takes an istream into the body of the Sales_data class.  

[ex7_12.h](./ex7_12.h)  

### 13. Rewrite the program from page 255 to use the istream constructor.  

[ex7_13.cpp](./ex7_13.cpp)  

### 14. Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.  

```cpp
Sales_data(): units_sold(0) , revenue(0){}
```
[ex7_14_sales_data.h](./ex7_14_sales_data.h)  

### 15. Add appropriate constructors to your Person class.  

[ex7_15.h](./ex7_15.h)  

### 16. What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a public specifier? What kinds should be private?  

> Those that wants to be called by outside clients should be declared public, and vice versa.  

### 17. What, if any, are the differences between using class or struct?  

> The members of class are private without specifiers, and the members of struct are public without specifiers.  

### 18. What is encapsulation? Why is it useful?  

> It provides methods to clients and hide the details that is no need for clients to know.  

+ User code cannot inadvertently corrupt the state of an encapsulation object.
+ The implementation of an encapsulated class can change over time without requiring changes in user-level code.  

### 19. Indicate which members of your Person class you would declare as public and which you would declare as private. Explain your choice.  

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

### 20. When are friends useful? Discuss the pros and cons of using friends.  

> In chapter 12 we will use StrBlobPtr and ConstStrBlobPtr, for one class that wants to read another class's private data, friends are useful.  

Pros:

+ The useful functions can refer to class members in the class scope without needing to explicitly prefix them with the class name.
+ You can access all the nonpublic members conveniently.
sometimes, more readable to the users of class.

Cons:

+ lessens encapsulation and therefore maintainability.
+ code verbosity, declarations inside the class, outside the class.

### 21. Update your Sales_data class to hide its implementation. The programs you’ve written to use Sales_data operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.  

> Now we're actually using class.  

[ex7_21_sales_data.h](./ex7_21_sales_data.h)   


### 22. Update your Person class to hide its implementation.  

[ex7_22.h](./ex7_22.h)  

### 23. Write your own version of the Screen class.  

[ex7_23.h](./ex7_23.h)

### 24. Give your Screen class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.  

[ex7_24.h](./ex7_24.h)  

### 25. Can Screen safely rely on the default versions of copy and assignment? If so, why? If not, why not?  

>  the class below which used only built-in type and strings can rely on the default version of copy and assignment. 

> In other word, we should write our own copy-constructor and assign-constructor when other self-created classes are in the class.  

### 26. Define Sales_data::avg_price as an inline function.  

[ex7_26_sales_data.h](./ex7_26_sales_data.h)  
[ex7_26_sales_data.cpp](./ex7_26_sales_data.cpp)

### 27. Add the move, set, and display operations to your version of Screen. Test your class by executing the following code:  

```cpp
Screen myScreen(5, 5, ’X’);
myScreen.move(4,0).set(’#’).display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```  

[ex7_27.h](./ex7_27.h)  
[ex7_27.cpp](./ex7_27.cpp)  

### 28. What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?

> It will duplicate it self to return a temporary copy instead of myScreen.  

### 29. Revise your Screen class so that move, set, and display functions return Screen and check your prediction from the previous exercise.  

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

### 30. It is legal but redundant to refer to members through the this pointer. Discuss the pros and cons of explicitly using the this pointer to access members.  

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

### 31. Define a pair of classes X and Y, in which X has a pointer to Y, and Y has an object of type X.  

[ex7_31.h](./ex7_31.h)  

### 32. Define your own versions of Screen and Window_mgr in which clear is a member of Window_mgr and a friend of Screen.  

[ex7_32.h](./ex7_32.h)  

### 33. What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.  

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

### 34. What would happen if we put the typedef of pos in the Screen class on page 285 as the last line in the class?

```
dummy_fcn(pos height)
           ^
Unknown type name 'pos'
```  

### 35. Explain the following code, indicating which definition of Type or initVal is used for each use of those names. Say how you would fix any errors.  

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

### 36. The following initializer is in error. Identify and fix the problem.  

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

### 37. Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:

```cpp
Sales_data first_item(cin);//use Sales_data(std::istream &is) ; 
int main() {
    Sales_data next;//use Sales_data(std::string s = "");
    Sales_data last("9-999-99999-9");// use Sales_data(std::string s = "");
}
```

### 38. We might want to supply cin as a default argument to the constructor that takes an istream&. Write the constructor declaration that uses cin as a default argument.  

```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```  

### 39. Would it be legal for both the constructor that takes a string and the one that takes an istream& to have default arguments? If not, why not?

> No. For no parameter situation it would be ambiguous.   

### 40. Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.  

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

### 41. Rewrite your own version of the Sales_data class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a Sales_data object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.  

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

### 42. For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.


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

