# Chapter 1 Getting Started  

## Exercise  

#### 1.1. Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the main program from page 2.  

> ./a.out  

#### 1.2. Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from main.  
[ex1_02.cpp](./ex1_02.cpp)
```
➜  ch01 git:(master) ✗ g++ ex1_2.cpp
➜  ch01 git:(master) ✗ ./a.out
➜  ch01 git:(master) ✗ echo $?
255
```  

> Why 255? see [this](https://tldp.org/LDP/abs/html/exitcodes.html)

#### 1.3. Write a program to print Hello, World on the standard output.  

[ex1_03.cpp](./ex1_03.cpp)  

#### 1.4. Our program used the addition operator, +, to add two numbers. Write a program that uses the multiplication operator, * , to print the product instead.  

[ex1_04.cpp](./ex1_04.cpp)  

#### 1.5. We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.  

[ex1_05.cpp](./ex1_05.cpp)  

#### 1.6. Explain whether the following program fragment is legal.  

```cpp
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```  

#### If the program is legal, what does it do? If the program is not legal, why not? How would you fix it?  

> **definitely not**  
lack of std::cout before line 2 and 3.  
```cpp
std::cout << "The sum of " << v1;
std::cout << " and " <<v2;
std::cout << " is " << v1 + v2 << std::endl;
```  

#### 1.7. Compile a program that has incorrectly nested comments.  

> Like this.  

```cpp
/*
* comment pairs /* */ cannot nest.
* ''cannot nest'' is considered source code,
* as is the rest of the program
*/
int main()
{
    return 0;
}

/*******************************************************
 * 1_7.cpp:3:3: error: empty character constant
 * ''cannot nest'' is considered source code,
 *  ^~~~~~~~
 * 1_7.cpp:3:16: error: empty character constant
 * * ''cannot nest'' is considered source code,
 *                ^~
 * 1_7.cpp:2:23: error: ‘cannot’ does not name a type
 * * comment pairs /*  cannot nest.
 */
```

#### 1.8. Indicate which, if any, of the following output statements are legal:  

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/"  /*  "/*"  */;
```  
#### After you’ve predicted what will happen, test your answers by compiling a program with each of these statements. Correct any errors you encounter.  

FIXED:  
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */";
std::cout << /* "*/" /* "/*" */;
```  

#### 1.9. Write a program that uses a while to sum the numbers from 50 to 100.  

[ex1_09.cpp](./ex1_09.cpp)  

#### 1.10. In addition to the ++ operator that adds 1 to its operand, there is a decrement operator (--) that subtracts 1. Use the decrement operator to write a while that prints the numbers from ten down to zero.  

[ex1_10.cpp](./ex1_10.cpp)   

#### 1.11. Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.  

[ex1_11.cpp](./ex1_11.cpp)  

#### 1.12. What does the following for loop do? What is the final value of sum?  

[ex1_12.cpp](./ex1_12.cpp)    

#### 1.13. Rewrite the first two exercises from § 1.4.1 (p. 13) using for loops.  

[ex1_13_09.cpp](./ex1_13_09.cpp)  
[ex1_13_10.cpp](./ex1_13_10.cpp)  
[ex1_13_11.cpp](./ex1_13_11.cpp)  

#### 1.14. Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form.  

while:  
> It only needs the expression, when there's no apparent way of incrementing value it should be the best choice.  

for:  
> It needs initial value, expression and incrementing code.   

#### 1.15. Write programs that contain the common errors discussed in the box on page 16. Familiarize yourself with the messages the compiler generates.  

[ex1_15.cpp](./ex1_15.cpp)   

#### 1.16. Write your own version of a program that prints the sum of a set of integers read from cin.  

[ex1_16.cpp](./ex1_16.cpp)    

#### 1.17. What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?  

[ex1_17.cpp](./ex1_17.cpp)    

> If all equal, the count will be printed out. If there are no duplicated values, A new line will be printed when Enter clicked.  

#### 1.18. Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.  

```
➜  ch01 git:(master) ✗ ./a.out 
114 114 114 114 114 514 514 514 514 514
114 occurs 5 times
514 occurs 5 times
```

#### 1.19. Revise the program you wrote for the exercises in § 1.4.1 (p. 13) that printed a range of numbers so that it handles input in which the first number is smaller than the second.  

> [ex1_11.cpp](./ex1_11.cpp) has already achieved that.  

#### 1.20. http://www.informit.com/title/0321714113 contains a copy of Sales_item.h in the Chapter 1 code directory. Copy that file to your working directory. Use it to write a program that reads a set of book sales transactions, writing each transaction to the standard output.   

[Sales_item.h](./Sales_item.h)  
[ex1_20.cpp](./ex1_20.cpp)  

#### 1.21. Write a program that reads two Sales_item objects that have the same ISBN and produces their sum.

[ex1_21.cpp](./ex1_21.cpp)   

#### 1.22. Write a program that reads several transactions for the same ISBN. Write the sum of all the transactions that were read.  

[ex1_22.cpp](./ex1_22.cpp)  

#### 1.23. Write a program that reads several transactions and counts how many transactions occur for each ISBN.  

[ex1_23.cpp](./ex1_23.cpp)  

```
➜  ch01 git:(master) ✗ ./a.out < book_sales       
0-201-70353-X 4 99.96 24.99 occurs 1 times.
0-201-82470-1 4 181.56 45.39 occurs 1 times.
0-201-88954-4 2 30 15 occurs 4 times.
0-399-82477-1 2 90.78 45.39 occurs 2 times.
0-201-78345-X 3 60 20 occurs 2 times.
```  

#### 1.24. Test the previous program by giving multiple transactions representing multiple ISBN s. The records for each ISBN should be grouped together.  

> See [ex1_23.cpp](./ex1_23.cpp)  

#### 1.25. Using the Sales_item.h header from the Web site, compile and execute the bookstore program presented in this section.  

> See [ex1_22.cpp](./ex1_22.cpp)  











