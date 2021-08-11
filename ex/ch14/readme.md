# Chapter 14 Overloaded Operations and Conversions  

## Note  

## Exercise  

#### 14.1 In what ways does an overloaded operator differ from a built-in operator? In what ways are overloaded operators the same as the built-in operators?  

> Differ:

- We can call an overloaded operator function directly.
- An overloaded operator function must either be a member of a class or have at least one parameter of class type.
- A few operators guarantee the order in which operands are evaluated. These overloaded versions of these operators do not preserve order of evaluation and/or short-circuit evaluation, it is usually a bad idea to overload them.  

> In particular, the operand-evaluation guarantees of the logical `AND`, logical `OR`, and comma operators are not preserved, Moreover, overloaded versions of `&&` or `||` operators do not preserve short-circuit evaluation properties of the built-in operators. Both operands are always evaluated.

Same:

- An overloaded operator has the same precedence and associativity as the corresponding built-in operator.

#### 14.2 Write declarations for the overloaded input, output, addition, and compound-assignment operators for Sales_data.  

[ex14_02_sales_data.h](./ex14_02_sales_data.h)  
[ex14_02_sales_data.cpp](./ex14_02_sales_data.cpp)  
[ex14_02_test.cpp](./ex14_02_test.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_02_test.cpp ex14_02_sales_data.cpp
➜  ch14 git:(master) ✗ ./a.out
1111 1 11
1111 1 11 11
```  

#### 14.3 Both string and vector define an overloaded == that can be used to compare objects of those types. Assuming svec1 and svec2 are vectors that hold strings, identify which version of == is applied in each of the following expressions:  

```cpp
(a) "cobble" == "stone"
(b) svec1[0] == svec2[0]
(c) svec1 == svec2
(d) "svec1[0] == "stone"
```  

> (a) neither. (b) string (c) vector (d) string  

#### 14.4 Explain how to decide whether the following should be class members:  

```
(a) %  
(b) %=  
(c) ++  
(d) ->  
(e) <<  
(f) &&  
(g) ==  
(h) ()  
```


(a) symmetric operator. Hence, non-member  

(b) changing state of objects. Hence, member  

(c) changing state of objects. Hence, member  

(d) = () [] -> must be member

(e) non-member

(f) symmetric , non-member

(g) symmetric , non-member

(h) = () [] -> must be member  

#### 14.5 In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of one of the following classes. Decide what, if any, overloaded operators your class should provide.  

> Book.  

[ex14_05.h](./ex14_05.h)  
[ex14_05.cpp](./ex14_05.cpp)  
[ex14_05_test.cpp](./ex14_05_test.cpp)  
```
➜  ch14 git:(master) ✗ g++ ex14_05_test.cpp ex14_05.cpp
➜  ch14 git:(master) ✗ ./a.out
123 CP5 Lippman 2012
```

#### 14.6 Define an output operator for your Sales_data class.  

> see   
[ex14_02_sales_data.h](./ex14_02_sales_data.h)  
[ex14_02_sales_data.cpp](./ex14_02_sales_data.cpp)  

#### 14.7 Define an output operator for you String class you wrote for the exercises in § 13.5 (p. 531).  

[ex14_07.h](./ex14_07.h)  
[ex14_07.cpp](./ex14_07.cpp)  
[ex14_07_test.cpp](./ex14_07_test.cpp)  


```
➜  ch14 git:(master) ✗ g++ ex14_07_test.cpp ex14_07.cpp
➜  ch14 git:(master) ✗ ./a.out
Hello World
```

#### 14.8 Define an output operator for the class you chose in exercise 7.40 from § 7.5.1 (p. 291).  

> see exercise 14.5  

#### 14.9 Define an input operator for your Sales_data class.  

> see exercise 14.2  

#### 14.10 Describe the behavior of the Sales_data input operator if given the following input:  

(a) 0-201-99999-9 10 24.95  
(b) 10 24.95 0-210-99999-9  

[ex14_10.cpp](./ex14_10.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_10.cpp ex14_02_sales_data.cpp
➜  ch14 git:(master) ✗ ./a.out
0-201-99999-9 10 24.95
0-201-99999-9 10 249.5 24.95
➜  ch14 git:(master) ✗ ./a.out
10 24.95 0-210-99999-9
10 24 22.8 0.95
```

#### 14.11 What, if anything, is wrong with the following Sales_data input operator? What would happen if we gave this operator the data in the previous exercise?  

```cpp
istream& operator>>(istream& in, Sales_data& s)
{
    double price;
    in >> s.bookNo >> s.units_sold >> price;
    s.revenue = s.units_sold * price;
    return in;
}
```  

> no input check. nothing happened.  

#### 14.12 Define an input operator for the class you used in exercise 7.40 from § 7.5.1 (p. 291). Be sure the operator handles input errors.  

> see exercise 14.5.  

#### 14.13 Which other arithmetic operators (Table 4.1 (p. 139)), if any, do you think Sales_data ought to support? Define any you think the class should include.  

> no others.  

#### 14.14 Why do you think it is more efficient to define operator+ to call operator+= rather than the other way around?  

> [SO](https://stackoverflow.com/questions/21071167/why-is-it-more-efficient-to-define-operator-to-call-operator-rather-than-the)  

#### 14.15 Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define any of the arithmetic operators? If so, implement them. If not, explain why not.  

[ex14_15.h](./ex14_15.h)  
[ex14_15.cpp](./ex14_15.cpp)  
[ex14_15_test.cpp](./ex14_15.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_15_test.cpp ex14_15.cpp
➜  ch14 git:(master) ✗ ./a.out
12345 CP5 Lippmen 2012 6
```  

#### 14.16 Define equality and inequality operators for your StrBlob (§ 12.1.1, p. 456), StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p. 526), and String (§ 13.5, p. 531) classes.  

[ex14_16_StrBlob.h](./ex14_16_StrBlob.h)  
[ex14_16_StrBlob.cpp](./ex14_16_StrBlob.cpp)  
[ex14_16_StrBlob_test.cpp](./ex14_16_StrBlob_test.cpp)   

```
➜  ch14 git:(master) ✗ g++ ex14_16_StrBlob_test.cpp ex14_16_StrBlob.cpp
➜  ch14 git:(master) ✗ ./a.out
Hello World Pezy 
```  

[ex14_16_StrVec.h](./ex14_16_StrVec.h)  
[ex14_16_StrVec.cpp](./ex14_16_StrVec.cpp)  
[ex14_16_StrVecMain.cpp](./ex14_16_StrVecMain.cpp)  



```
➜  ch14 git:(master) ✗ g++ ex14_16_StrVecMain.cpp ex14_16_StrVec.cpp
➜  ch14 git:(master) ✗ ./a.out
capacity(reserve to 6): 6
capacity(reserve to 4): 6
hello
world


-EOF-
hello
-EOF-
hello world pezy 
hello world pezy 
```

[ex14_16_String.h](./ex14_16_String.h)  
[ex14_16_String.cpp](./ex14_16_String.cpp)  
[ex14_16_StringMain.cpp](./ex14_16_StringMain.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_16_StringMain.cpp ex14_16_String.cpp
➜  ch14 git:(master) ✗ ./a.out
s2 == s1
hello
hello
temporary
temporary
hello
hello
hello
world
world
good job
Input a string: vergil
vergil
```


#### 14.17 Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the equality operators? If so, implement them. If not, explain why not.  

> Yes. See exercise 14.15.  

#### 14.18 Define relational operators for your StrBlob, StrBlobPtr, StrVec, and String classes.  

[ex14_18_StrBlob.h](./ex14_18_StrBlob.h)  
[ex14_18_StrBlob.cpp](./ex14_18_StrBlob.cpp)  
[ex14_18_StrBlobTest.cpp](./ex14_18_StrBlobTest.cpp)   

```
➜  ch14 git:(master) ✗ g++ ex14_18_StrBlobTest.cpp ex14_18_StrBlob.cpp
➜  ch14 git:(master) ✗ ./a.out
a b c 
```  
[ex14_18_String.h](./ex14_18_String.h)  
[ex14_18_String.cpp](./ex14_18_String.cpp)  
[ex14_18_StringMain.cpp](./ex14_18_StringMain.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_18_StringMain.cpp ex14_18_String.cpp
➜  ch14 git:(master) ✗ ./a.out
s2 == s1
hello
hello
temporary
temporary
hello
hello
hello
world
world
good job
Input a string: ok
ok
s6 > s1
```  

[ex14_18_StrVec.h](./ex14_18_StrVec.h)  
[ex14_18_StrVec.cpp](./ex14_18_StrVec.cpp)  
[ex14_18_StrVecMain.cpp](./ex14_18_StrVecMain.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_18_StrVecMain.cpp ex14_18_StrVec.cpp
➜  ch14 git:(master) ✗ ./a.out
capacity(reserve to 6): 6
capacity(reserve to 4): 6
hello
world


-EOF-
hello
-EOF-
hello world pezy 
hello world pezy 
1
```  

#### 14.19 Should the class you chose for exercise 7.40 from § 7.5.1 (p. 291) define the relational operators? If so, implement them. If not, explain why not.  

> See exercise 14.15.  

#### 14.20 Define the addition and compound-assignment operators for your Sales_data class.  

> See exercose 14.2.  

#### 14.21 Write the Sales_data operators so that + does the actual addition and += calls +. Discuss the disadvantages of this approach compared to the way these operators were defined in § 14.3 (p. 560) and § 14.4 (p. 564).  

```cpp
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    Sales_data old_data = *this;
    *this = old_data + rhs;
    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}
```  

#### 14.22 Define a version of the assignment operator that can assign a string representing an ISBN to a Sales_data.

[ex14_22_sales_data.h](./ex14_22_sales_data.h)  
[ex14_22_sales_data.cpp](./ex14_22_sales_data.cpp)  
[ex14_22_sales_data_test.cpp](./ex14_22_sales_data_test.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_22_sales_data_test.cpp ex14_22_sales_data.cpp
➜  ch14 git:(master) ✗ ./a.out
C++ Primer 5th 0 0 0
```

#### 14.23 Define an initializer_list assignment operator for your version of the StrVec class.  

[ex14_23.h](./ex14_23.h)  
[ex14_23.cpp](./ex14_23.cpp)  
[ex14_23_TEST.cpp](./ex14_23_TEST.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_23_TEST.cpp ex14_23.cpp
➜  ch14 git:(master) ✗ ./a.out
capacity(reserve to 6): 6
capacity(reserve to 4): 6
hello
world


-EOF-
hello
-EOF-
hello world pezy 
hello world pezy 
1
```  

#### 14.24 Decide whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define those operators.  

[ex14_24.h](./ex14_24.h)  
[ex14_24.cpp](./ex14_24.cpp)  
[ex14_24_TEST.cpp](./ex14_24_TEST.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_24_TEST.cpp ex14_24.cpp
➜  ch14 git:(master) ✗ ./a.out
moving =destroying
19 3 27347
destroying
destroying
```  

#### 14.25 Implement any other assignment operators your class should define. Explain which types should be used as operands and why.  

> See exercise 14.24  

#### 14.26 Define subscript operators for your StrVec, String, StrBlob, and StrBlobPtr classes.  

[ex14_26_StrBlob.h](./ex14_26_StrBlob.h)  
[ex14_26_StrBlob.cpp](./ex14_26_StrBlob.cpp)  
[ex14_26_StrBlobTest.cpp](./ex14_26_StrBlobTest.cpp)   

```
➜  ch14 git:(master) ✗ g++ ex14_26_StrBlobTest.cpp ex14_26_StrBlob.cpp 
➜  ch14 git:(master) ✗ ./a.out
a b c 
b
```  

[ex14_26_String.h](./ex14_26_String.h)  
[ex14_26_String.cpp](./ex14_26_String.cpp)  
[ex14_26_StringMain.cpp](./ex14_26_StringMain.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_26_StringMain.cpp ex14_26_String.cpp 
➜  ch14 git:(master) ✗ ./a.out
s2 == s1
hello
hello
temporary
temporary
hello
hello
hello
world
world
good job
Input a string: vergil
vergil
s6 > s1
r
```

[ex14_26_StrVec.h](./ex14_26_StrVec.h)  
[ex14_26_StrVec.cpp](./ex14_26_StrVec.cpp)  
[ex14_26_StrVecMain.cpp](./ex14_26_StrVecMain.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_26_StrVecMain.cpp ex14_26_StrVec.cpp
➜  ch14 git:(master) ✗ ./a.out
capacity(reserve to 6): 6
capacity(reserve to 4): 6
hello
world


-EOF-
hello
-EOF-
hello world pezy 
hello world pezy 
1
pezy
```  

#### 14.27 Add increment and decrement operators to your StrBlobPtr class.  

[ex14_27_28_StrBlob.h](./ex14_27_28_StrBlob.h)  
[ex14_27_28_StrBlob.cpp](./ex14_27_28_StrBlob.cpp)  
[ex14_27_28_StrBlobTest.cpp](./ex14_27_28_StrBlobTest.cpp)   

```
➜  ch14 git:(master) ✗ g++ ex14_27_28_StrBlobTest.cpp ex14_27_28_StrBlob.cpp
➜  ch14 git:(master) ✗ ./a.out
a b c 
b
```  

#### 14.28 Define addition and subtraction for StrBlobPtr so that these operators implement pointer arithmetic (§ 3.5.3, p. 119).  

> See exercise 14.27.  

#### 14.29 We did not define a const version of the increment and decrement operators. Why not?  

> Because ++ and -- change the state of the object. Hence ,it's meaningless to do so.  

#### 14.30 Add dereference and arrow operators to your StrBlobPtr class and to the ConstStrBlobPtr class that you defined in exercise 12.22 from § 12.1.6 (p. 476). Note that the operators in constStrBlobPtr must return const references because the data member in constStrBlobPtr points to a const vector.  

[ex14_30_StrBlob.h](./ex14_30_StrBlob.h)  
[ex14_30_StrBlob.cpp](./ex14_30_StrBlob.cpp)  
[ex14_30_StrBlobTest.cpp](./ex14_30_StrBlobTest.cpp)    

```
➜  ch14 git:(master) ✗ g++ ex14_30_StrBlobTest.cpp ex14_30_StrBlob.cpp
➜  ch14 git:(master) ✗ ./a.out
a b c 
1
```  

#### 14.31 Our StrBlobPtr class does not define the copy constructor, assignment operator, or a destructor. Why is that okay?  

> Applying the Rule of 3/5: There is no dynamic allocation to deal with, so the synthesized destructor is enough. Moreover, no unique is needed. Hence, the synthesized ones can handle all the corresponding operations.  

#### 14.32 Define a class that holds a pointer to a StrBlobPtr. Define the overloaded arrow operator for that class.  

[ex14_32.h](./ex14_32.h)  
[ex14_32.cpp](./ex14_32.cpp)  

```
ch14 git:(master) ✗ g++ ex14_32.cpp ex14_30_StrBlob.cpp
ch14 git:(master) ✗ ./a.out
hello
```

#### 14.33 How many operands may an overloaded function-call operator take?  

> An overloaded operator function has the same number of parameters as the operator has operands. Hence the maximum value should be around 256.  

> [SO](https://stackoverflow.com/questions/21211889/how-many-operands-may-an-overloaded-function-call-operator-take)  

#### 14.34 Define a function-object class to perform an if-then-else operation: The call operator for this class should take three parameters. It should test its first parameter and if that test succeeds, it should return its second parameter; otherwise, it should return its third parameter.  

```cpp
struct Test {
    int operator()(bool b, int iA, int iB) {
        return b ? iA : iB;
    }
};
```  

#### 14.35 Write a class like PrintString that reads a line of input from an istream and returns a string representing what was read. If the read fails, return the empty string.  

[ex14_35.cpp](./ex14_35.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_35.cpp
➜  ch14 git:(master) ✗ ./a.out
you're mie
you're mie
```  

#### 14.36 Use the class from the previous exercise to read the standard input, storing each line as an element in a vector.  

[ex14_36.cpp](./ex14_36.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_36.cpp
➜  ch14 git:(master) ✗ ./a.out
come on
you can do it
over here
come on you can do it over here 
```  

#### 14.37 Write a class that tests whether two values are equal. Use that object and the library algorithms to write a program to replace all instances of a given value in a sequence.   

[ex14_37.cpp](./ex14_37.cpp)

```
➜  ch14 git:(master) ✗ g++ ex14_37.cpp
➜  ch14 git:(master) ✗ ./a.out
5 2 1 4 5 7 8 6 
```

#### 14.38 Write a class that tests whether the length of a given string matches a given bound. Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.  

[ex14_38_39.cpp](./ex14_38_39.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_38_39.cpp 
➜  ch14 git:(master) ✗ ./a.out
65, 65
```  

#### 14.39 Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.  

> see ex14.38.  

#### 14.40 Rewrite the biggies function from § 10.3.2 (p. 391) to use function-object classes in place of lambdas.  

[ex14_40.cpp](./ex14_40.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_40.cpp
➜  ch14 git:(master) ✗ ./a.out
5 words of length 4 or longer
over slow jumps quick turtle 
```  

#### 14.41 Why do you suppose the new standard added lambdas? Explain when you would use a lambda and when you would write a class instead.  

> IMO, lambda is quite handy to use. Lambda can be used when the functor is not used frequently nor complicated, whereas functor is supposed to call more times than lambda or quite complicated to implement as a lambda.

#### 14.42 Using library function objects and adaptors, define an expression to  

(a) Count the number of values that are greater than 1024  
(b) Find the first string that is not equal to pooh  
(c) Multiply all values by 2  

[ex14_42.cpp](./ex14_42.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_42.cpp
➜  ch14 git:(master) ✗ ./a.out
2
pezy
2 222 2222 22222 
```  

#### 14.43 Using library function objects, determine whether a given int value is divisible by any element in a container of ints.  

[ex14_43.cpp](./ex14_43.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_43.cpp
➜  ch14 git:(master) ✗ ./a.out
50
Yes!
```  

#### 14.44 Write your own version of a simple desk calculator that can handle binary operations.  

[ex14_44.cpp](./ex14_44.cpp)  

```
➜  ch14 git:(master) ✗ g++ ex14_44.cpp
➜  ch14 git:(master) ✗ ./a.out

pleasr enter: num operator num :
5 + 5
10
pleasr enter: num operator num :
5 * 10
50
pleasr enter: num operator num :
terminate called after throwing an instance of 'std::bad_function_call'
  what():  bad_function_call
[1]    16988 abort (core dumped)  ./a.out
```

#### 14.45 Write conversion operators to convert a Sales_data to string and to double. What values do you think these operators should return?  

[ex14_45_sales_data.h](./ex14_45_sales_data.h)  
[ex14_45_sales_data.cpp](./ex14_45_sales_data.cpp)  
[ex14_45_sales_data_test.cpp](./ex14_45_sales_data_test.cpp)    

```
➜  ch14 git:(master) ✗ g++ ex14_45_sales_data_test.cpp ex14_45_sales_data.cpp
➜  ch14 git:(master) ✗ ./a.out
C++ Primer 5th 4 426 106.5
C++ Primer 5th
106.5
```  

#### 14.46 Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.  

> It's a bad idea to do so, because these conversion is misleading.explicit should be added to prevent implicit conversion.

#### 14.47 Explain the difference between these two conversion operators:  

```cpp
struct Integral {
    operator const int();   // meaningless, it will be ignored by compiler.
    operator int() const;   // promising that this operator will not change the state of the obj
};
```  

#### 14.48 Determine whether the class you used in exercise 7.40 from § 7.5.1 (p. 291) should have a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.  

> A conversion to bool can be useful for the class Date. But it must be an explicit one to prevent any automatic conversion.  

#### 14.49 Regardless of whether it is a good idea to do so, define a conversion to bool for the class from the previous exercise.  

[ex14_49_TEST.cpp](./ex14_49_TEST.cpp)  
[ex14_49.cpp](./ex14_49.cpp)  
[ex14_49.h](./ex14_49.h)  

```
➜  ch14 git:(master) ✗ g++ ex14_49_TEST.cpp ex14_49.cpp
➜  ch14 git:(master) ✗ ./a.out
12 4 2015
destroying
``` 

#### 14.50 Show the possible class-type conversion sequences for the initializations of ex1 and ex2. Explain whether the initializations are legal or not.

```cpp
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;  // error ambiguous: double or float?
float ex2 = ldObj;// legal
```  

#### 14.51 Show the conversion sequences (if any) needed to call each version of calc and explain why the best viable function is selected.

```cpp
void calc(int);
void calc(LongDouble);
double dval;
calc(dval); // which calc ?
```  

best viable function: void calc(int). cause class-type conversion is the lowest ranked.

review the order:  

1. exact match
2. const conversion
3. promotion
4. arithmetic or pointer conversion
5. class-type conversion  

#### 14.52 Which operator+, if any, is selected for each of the addition expressions? List the candidate functions, the viable functions, and the type conversions on the arguments for each viable function:  

```cpp
struct LongDouble {
    // member operator+ for illustration purposes; + is usually a nonmember
    LongDouble operator+(const SmallInt&);
    // other members as in § 14.9.2 (p. 587)
};
LongDouble operator+(LongDouble&, double);
SmallInt si;
LongDouble ld;
ld = si + ld;
ld = ld + si;
```

> ld = si + ld; is ambiguous. ld = ld + si can use both 1 and 2, but 1 is more exactly. (in the 2, SmallInt need to convert to double)  

#### 14.53 Given the definition of SmallInt on page 588, determine whether the following addition expression is legal. If so, what addition operator is used? If not, how might you change the code to make it legal?  

```cpp
SmallInt s1;
double d = s1 + 3.14;
```

ambiguous.

Fixed:

```cpp
SmallInt s1;
double d = s1 + SmallInt(3.14);
```
