# Chapter 3 Strings, Vectors, and Arrays  

## Exercise  

#### 3.1. Rewrite the exercises from § 1.4.1 (p. 13) and § 2.6.2 (p. 76) with appropriate using declarations.  

[ex3_01_1.cpp](./ex3_01_1.cpp)  
[ex3_01_2.cpp](./ex3_01_2.cpp)  

#### 3.2. Write a program to read the standard input a line at a time. Modify your program to read a word at a time.  

[ex3_02_1.cpp](./ex3_02_1.cpp)  
[ex3_02_2.cpp](./ex3_02_2.cpp)  

#### 3.3. Explain how whitespace characters are handled in the string input operator and in the getline function.  

> getline will read all space character. 

> cin will only skip through every space character until first non-space character, and read through the string until a space.  

#### 3.4. Write a program to read two strings and report whether the strings are equal. If not, report which of the two is larger. Now, change the program to report whether the strings have the same length, and if not, report which is longer.  

[ex3_04_1.cpp](./ex3_04_1.cpp)  
[ex3_04_2.cpp](./ex3_04_2.cpp)  

#### 3.5. Write a program to read strings from the standard input, concatenating what is read into one large string. Print the concatenated string. Next, change the program to separate adjacent input strings by a space.   

[ex3_05.cpp](./ex3_05.cpp)    

#### 3.6. Use a range for to change all the characters in a string to X.  

[ex3_06.cpp](./ex3_06.cpp)  

#### 3.7. What would happen if you define the loop control variable in the previous exercise as type char? Predict the results and then change your program to use a char to see if you were right.  

[ex3_07.cpp](./ex3_07.cpp)  

> It will modify the temporary copy.  
> We must manually add a reference to ensure the actual modification take place.  

#### 3.8. Rewrite the program in the first exercise, first using a while and again using a traditional for loop. Which of the three approaches do you prefer and why?  

[ex3_08.cpp](./ex3_08.cpp)  

> When range-for is possible I would choose range-for to traverse every element of a container.  

#### 3.9. What does the following program do? Is it valid? If not, why not?  

```cpp
string s;
cout << s[0] << endl;
```

> Invalid, undefined behavior.  

#### 3.10. Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed.  

[ex3_10.cpp](./ex3_10.cpp)  

#### 3.11. Is the following range for legal? If so, what is the type of c?  

```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```

> When you don't change c's value, it's legal, else it's illegal.  

```cpp
cout << c;  // legal.
c = 'X';    // illegal.
```

> The type of c is const char&. read-only variable is not assignable.  

#### 3.12. Which, if any, of the following vector definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.  

(a) vector<vector<int>> ivec;  
> legal.  

(b) vector<string> svec = ivec;  
> illegal.  

(c) vector<string> svec(10, "null");
> legal.  

#### 3.13. How many elements are there in each of the following vectors? What are the values of the elements?  

```cpp
vector<int> v1;         // size:0,  no values.
vector<int> v2(10);     // size:10, value:0
vector<int> v3(10, 42); // size:10, value:42
vector<int> v4{10};     // size:1,  value:10
vector<int> v5{10, 42}; // size:2,  value:10, 42
vector<string> v6{10};  // size:10, value:""
vector<string> v7{10, "hi"};  // size:10, value:"hi"
```  

#### 3.14. Write a program to read a sequence of ints from cin and store those values in a vector.

[ex3_14.cpp](./ex3_14.cpp)  

```
➜  ch03 git:(master) ✗ g++ 3_14.cpp
➜  ch03 git:(master) ✗ ./a.out
1
2
3
4
5
```  

#### 3.15. Repeat the previous program but read strings this time.  

[ex3_15.cpp](./ex3_15.cpp)  

```
➜  ch03 git:(master) ✗ g++ ex3_15.cpp 
➜  ch03 git:(master) ✗ ./a.out
as 
the
air
to
a
bird
```  

#### 3.16. Write a program to print the size and contents of the vectors from exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you were wrong.  

[ex3_16.cpp](./ex3_16.cpp)  

```
➜  ch03 git:(master) ✗ g++ ex3_16.cpp
➜  ch03 git:(master) ✗ ./a.out
{
 "v1":{"size":"0","value":[]}
 "v2":{"size":"10","value":[0,0,0,0,0,0,0,0,0,0]}
 "v3":{"size":"10","value":[42,42,42,42,42,42,42,42,42,42]}
 "v4":{"size":"1","value":[10]}
 "v5":{"size":"2","value":[10,42]}
 "v6":{"size":"10","value":[(null),(null),(null),(null),(null),(null),(null),(null),(null),(null)]}
 "v7":{"size":"10","value":[hi,hi,hi,hi,hi,hi,hi,hi,hi,hi]}
}
```  

#### 3.17. Read a sequence of words from cin and store the values a vector. After you’ve read all the words, process the vector and change each word to uppercase. Print the transformed elements, eight words to a line.  

[ex3_17.cpp](./ex3_17.cpp)  

```
➜  ch03 git:(master) ✗ g++ ex3_17.cpp
➜  ch03 git:(master) ✗ ./a.out
as
the  
air
to
a
bird
As The Air To A Bird 
```  

#### 3.18. Is the following program legal? If not, how might you fix it?  

```cpp
vector<int> ivec;
ivec[0] = 42;
```

FIXED: 

```cpp
#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> ivec;
    ivec.push_back(42);
    return 0;
}
```  

#### 3.19. List three ways to define a vector and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.  

```cpp
#include<iostream>
#include<vector>
using std::vector;

int main(){
    vector<int> num(10,42);
    vector<int> num2 = {42,42,42,42,42,42,42,42,42,42};
    vector<int> num3{42,42,42,42,42,42,42,42,42,42};

    return 0;
    //I will choose the first one, concise.  
}
```  

#### 3.20. Read a set of integers into a vector. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.  

[ex3_20_1.cpp](./ex3_20_1.cpp)   

```
➜  ch03 git:(master) ✗ g++ ex3_20_1.cpp 
➜  ch03 git:(master) ✗ ./a.out
1 2 3 4 5 6 7 8 9 10
3 5 7 9 11 13 15 17 19 
``` 

[ex3_20_2.cpp](./ex3_20_2.cpp)    

```
➜  ch03 git:(master) ✗ g++ ex3_20_2.cpp
➜  ch03 git:(master) ✗ ./a.out
1 2 3 4 5 6 7 8 9 10
11 11 11 11 11 
``` 

#### 3.21. Redo the first exercise from § 3.3.3 (p. 105) using iterators.  

[ex3_21.cpp](./ex3_21.cpp)   

```
➜  ch03 git:(master) ✗ g++ ex3_21.cpp
➜  ch03 git:(master) ✗ ./a.out
size: 0; no values.
size: 10; values:0,0,0,0,0,0,0,0,0,0.
size: 10; values:42,42,42,42,42,42,42,42,42,42.
size: 1; values:10.
size: 2; values:10,42.
size: 10; values:(null),(null),(null),(null),(null),(null),(null),(null),(null),(null).
size: 10; values:hi,hi,hi,hi,hi,hi,hi,hi,hi,hi.
```  

#### 3.22. Revise the loop that printed the first paragraph in text to instead change the elements in text that correspond to the first paragraph to all uppercase. After you’ve updated text, print its contents.  

[ex3_22.cpp](./ex3_22.cpp)

```
➜  ch03 git:(master) ✗ g++ ex3_22.cpp
➜  ch03 git:(master) ✗ ./a.out
we show no mercy.
WE SHOW NO MERCY.
```  

#### 3.23. Write a program to create a vector with ten int elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the vector.  

[ex3_23.cpp](./ex3_23.cpp)  

```
➜  ch03 git:(master) ✗ g++ ex3_23.cpp
➜  ch03 git:(master) ✗ ./a.out
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20 
```  

#### 3.24. Redo the last exercise from § 3.3.3 (p. 105) using iterators.  

[ex3_24.cpp](./ex3_24.cpp)  

```
➜  ch03 git:(master) ✗ g++ ex3_24.cpp
➜  ch03 git:(master) ✗ ./a.out
1 2 3 4 5 6 7 8 9 10
3 5 7 9 11 13 15 17 19 
```  

#### 3.25. Rewrite the grade clustering program from § 3.3.3 (p. 104) using iterators instead of subscripts.  

[ex3_25.cpp](./ex3_25.cpp)   

```
➜  ch03 git:(master) ✗ g++ ex3_25.cpp
➜  ch03 git:(master) ✗ ./a.out
50 50 50 100 100 69 76 82 81
0 0 0 0 0 3 1 1 2 0 2 
```

#### 3.26. In the binary search program on page 112, why did we write mid = beg + (end - beg) / 2; instead of mid = (beg + end) /2;?   

> the iterator of vector don't define the + operator between the two iterators. beg + end is illegal.    

#### 3.27. Assuming txt_size is a function that takes no arguments and returns an int value, which of the following definitions are illegal? Explain why.  

```cpp
unsigned buf_size = 1024;
(a) int ia[buf_size];//illegal, The dimension value must be a constant expression.
(b) int ia[4 * 7 - 14];//legal.  
(c) int ia[txt_size()];//illegal, The dimension value must be a constant expression.
(d) char st[11] = "fundamental";// illegal, the string's size is 12.
```  

#### 3.28. What are the values in the following arrays?  

```cpp
string sa[10];//empty string
int ia[10];//0
int main() {
    string sa2[10];//empty string
    int ia2[10];//undefined  
}
```  

#### 3.29. List some of the drawbacks of using an array instead of a vector.  

> There's no convenient way of adding element into the end of the array,  

#### 3.30. Identify the indexing errors in the following code:  

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
ia[ix] = ix;
```  

> ix cannot equal to array_size.  

#### 3.31. Write a program to define an array of ten ints. Give each element the same value as its position in the array.  


[ex3_31.cpp](./ex3_31.cpp)   

#### 3.32. Copy the array you defined in the previous exercise into another array. Rewrite your program to use vectors.  

[ex3_32.cpp](./ex3_32.cpp)   

```
➜  ch03 git:(master) ✗ g++ ex3_32.cpp
➜  ch03 git:(master) ✗ ./a.out
0 1 2 3 4 5 6 7 8 9 
```  

#### 3.33. What would happen if we did not initialize the scores array in the program on page 116?  

> the array is undefined. the value will be unknown.  

#### 3.34. Given that p1 and p2 point to elements in the same array, what does the following code do? Are there values of p1 or p2 that make this code illegal?

p1 += p2 - p1;  

> p1 += p2 - p1; same as p1 = p2;. If p2 and p1 are legal, this code always legal.  

#### 3.35. Using pointers, write a program to set the elements in an array to zero.  

[ex3_35.cpp](./ex3_35.cpp)  


```
➜  ch03 git:(master) ✗ g++ ex3_35.cpp
➜  ch03 git:(master) ✗ ./a.out
0 0 0 0 0 0 0 0 0 0 
```  

#### 3.36. Write a program to compare two arrays for equality. Write a similar program to compare two vectors.  

[ex3_36.cpp](./ex3_36.cpp)  
```
➜  ch03 git:(master) ✗ g++ ex3_36.cpp
➜  ch03 git:(master) ✗ ./a.out
The two arrays are not equal.
==========
The two vectors are equal.
```  

#### 3.37. What does the following program do?  

```cpp
const char ca[] = {’h’, ’e’, ’l’, ’l’, ’o’};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```  

> print out every element in the array.  

-----
**WARNING!!!!**
When we use a string, the compiler put it in the section `.rodata`, the code uses C-style character string without adding a '\0' in the end of `ca`.
So, when we code like this:

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char s[] = "world";
const char *cp = ca;
while (*cp) {
cout << *cp;
++cp;
}
```

The code will print "helloworld" when you run it.
because the character list in the `.rodata` like this:

    h e l l o w o r l d \0
`While(*cp)` judge weather *cp is 0 or not. when *cp is not 0, it will print the character until 0.
When you change the code like this:

    const char ca[] = {'h', 'e', 'l', 'l', 'o', '\0'};
the character list in the `.rodata`:

    h e l l o \0 w o r l d \0
The program will run correctly. So when using C-style character string, be careful!!

-----

see `.rodata`, you can use this command:

    hexdump -C a.out


#### 3.38. In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

> Because Subtracting two points gives a logically explainable result - the offset in memory between two points. Similarly, you can subtract or add an integral number to/from a pointer, which means "move the pointer up or down". Adding a pointer to a pointer is something which is hard to explain. The result is meaningless.

[Why I can't add pointer](https://stackoverflow.com/questions/2935038/why-cant-i-add-pointers)  

#### 3.39. Write a program to compare two strings. Now write a program to compare the values of two C-style character strings.  

[ex3_39.cpp](./ex3_39.cpp)  

```
➜  ch03 git:(master) ✗ g++ ex3_39.cpp
➜  ch03 git:(master) ✗ ./a.out
Blue < Espeon
=========
Blue < Espeon
```  

#### 3.40. Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use strcpy and strcat to copy the two arrays into the third.  

[ex3_40.cpp](./ex3_40.cpp)   

```
➜  ch03 git:(master) ✗ g++ ex3_40.cpp
➜  ch03 git:(master) ✗ ./a.out
Hello world!
```  

#### 3.41. Write a program to initialize a vector from an array of ints.  

[ex3_41.cpp](./ex3_41.cpp)   

```
➜  ch03 git:(master) ✗ g++ ex3_41.cpp
➜  ch03 git:(master) ✗ ./a.out
0 1 2 3 4 5 6 7 8 9 
```  

#### 3.42. Write a program to copy a vector of ints into an array of ints.  

[ex3_42.cpp](./ex3_42.cpp)   

```
➜  ch03 git:(master) ✗ g++ ex3_42.cpp
➜  ch03 git:(master) ✗ ./a.out
0 1 2 3 4 5 6 7 8 9 
```  

#### 3.43. Write three different versions of a program to print the elements of ia. One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. In all three programs write all the types directly. That is, do not use a type alias, auto, or decltype to simplify the code.  

[ex3_43.cpp](./ex3_43.cpp)    

```
➜  ch03 git:(master) ✗ g++ ex3_43.cpp
➜  ch03 git:(master) ✗ ./a.out
0 1 2 3 4 5 6 7 8 9 10 11 
0 1 2 3 4 5 6 7 8 9 10 11 
0 1 2 3 4 5 6 7 8 9 10 11 
```  

#### 3.44. Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.  

[ex3_44.cpp](./ex3_44.cpp)    

```
➜  ch03 git:(master) ✗ g++ ex3_44.cpp
➜  ch03 git:(master) ✗ ./a.out
0 1 2 3 4 5 6 7 8 9 10 11 
0 1 2 3 4 5 6 7 8 9 10 11 
0 1 2 3 4 5 6 7 8 9 10 11 
```

#### 3.45. Rewrite the programs again, this time using auto.  

[ex3_45.cpp](./ex3_45.cpp)    

```
➜  ch03 git:(master) ✗ g++ ex3_45.cpp
➜  ch03 git:(master) ✗ ./a.out
0 1 2 3 4 5 6 7 8 9 10 11 
0 1 2 3 4 5 6 7 8 9 10 11 
0 1 2 3 4 5 6 7 8 9 10 11 
```