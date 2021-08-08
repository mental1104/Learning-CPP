# Chapter 5 Statement  

#### 5.1 What is a null statement? When might you use a null statement?  

> ; // null statement  

> For example, the spin-lock used in OS just use the null statement endlessly waiting for condition to be false.  

#### 5.2 What is a block? When might you might use a block?  

> {  }  

> When I want to declare a variable that will be destructed while it reaches the end of that block or used in loop for several statements.  

#### 5.3 Use the comma operator (§ 4.10, p. 157) to rewrite the while loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain whether this rewrite improves or diminishes the readability of this code.  

```cpp
#include <iostream>
int main()
{
    int sum = 0, val = 1;
    while (val <= 10)
        sum += val, ++val;
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;

    return 0;
}
```

> This rewrite diminishes the readability of the code.   

#### 5.4 Explain each of the following examples, and correct any problems you detect.  

```cpp
(a) while (string::iterator iter != s.end()) { /* . . . */ }
(b) while (bool status = find(word)) { /* . . . */ }
if (!status) { /* . . . */ }
```

(a) iter point at nothing. invalid.  

```cpp
std::string::iterator iter = s.begin();
    while (iter != s.end()) { /* . . . */ }
```

(b) The if statement is not in the while's block. so the status is invalid. And if find(word) return true, it will go through the while block. we should declare the status before while.  

```cpp
bool status;
while ((status = find(word))) {/* ... */}
if (!status) {/* ... */}
```  


#### 5.5 Using an if–else statement, write your own version of the program to generate the letter grade from a numeric grade.  

[ex5_05.cpp](./ex5_05.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_05.cpp
➜  ch05 git:(master) ✗ ./a.out
90
A-
100
A++
95
A
30
F
60
D-
61
D-
59
F
66
D
70
C-
69
D+
```  

#### 5.6 Rewrite your grading program to use the conditional operator (§ 4.7, p. 151) in place of the if–else statement.  

[ex5_06.cpp](./ex5_06.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_06.cpp
➜  ch05 git:(master) ✗ ./a.out
100
A++
60
D-
99
A+
96
A
```  

#### 5.7 Correct the errors in each of the following code fragments:  

```
(a) if (ival1 != ival2)
        ival1 = ival2
    else 
        ival1 = ival2 = 0;
(b) if (ival < minval)
        minval = ival;
    occurs = 1;
(c) if (int ival = get_value())
        cout << "ival = " << ival << endl;
    if (!ival)
        cout << "ival = 0\n";
(d) if (ival = 0)
        ival = get_value();
```

```
(a) lost semicolon.
(b) lost block.  
(c) definition of ival shouldn't be in the expression zone.  
(d) `ival == 0`  
``` 

#### 5.8 What is a “dangling else”? How are else clauses resolved in C++?  

> the problem of how to process nested if statements in which there are more ifs than elses. In C++, an else is always paired with the closest preceding unmatched if.  

#### 5.9 Write a program using a series of if statements to count the number of vowels in text read from cin.  

[ex5_09.cpp](./ex5_09.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_09.cpp
➜  ch05 git:(master) ✗ ./a.out
a
e i o u d a e i o u
Number of vowel a:      2
Number of vowel e:      2
Number of vowel i:      2
Number of vowel o:      2
Number of vowel u:      2
```  

#### 5.10 There is one problem with our vowel-counting program as we’ve implemented it: It doesn’t count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel—that is, your program should count both ’a’ and ’A’ as part of aCnt, and so forth.  

[ex5_10.cpp](./ex5_10.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_10.cpp
➜  ch05 git:(master) ✗ ./a.out
a e i o u A E i I I i O o U u
Number of vowel a(A):   2
Number of vowel e(E):   2
Number of vowel i(I):   5
Number of vowel o(O):   3
```

#### 5.11 Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.  

[ex5_11.cpp](./ex5_11.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_11.cpp
➜  ch05 git:(master) ✗ ./a.out
a i e o u e i a A o i I         O       O 
Number of vowel a(A):   3
Number of vowel e(E):   2
Number of vowel i(I):   4
Number of vowel o(O):   4
Number of vowel u(U):   1
Number of space:        14
Number of tab char:     2
Number of new line:     1
```  

#### 5.12 Modify our vowel-counting program so that it counts the number of occurrences of the following two-character sequences: ff, fl, and fi.  

[ex5_12.cpp](./ex5_12.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_12.cpp
➜  ch05 git:(master) ✗ ./a.out
ff fl fi ff fl ff ff ff fiNumber of vowel a(A):         0
Number of vowel e(E):   0
Number of vowel i(I):   2
Number of vowel o(O):   0
Number of vowel u(U):   0
Number of space:        8
Number of tab char:     0
Number of new line:     0
Number of ff:   5
Number of fl:   2
Number of fi:   2
```  

#### 5.13 Each of the programs in the highlighted text on page 184 contains a common programming error. Identify and correct each error.  

```cpp
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
        case 'a': aCnt++;//lost break.
        case 'e': eCnt++;
        default: iouCnt++;
    }
(b) unsigned index = some_value();
    switch (index) {
        case 1:
            int ix = get_value();
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size()-1;//ix is not in the scope.  
            ivec[ ix ] = index;
    }
(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit) {
        case 1, 3, 5, 7, 9://should be case 1: case 3: case 5： case 7: case 9: 
            oddcnt++;
            break;
        case 2, 4, 6, 8, 10:
            evencnt++;
            break;
    }
(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
        case ival:
            bufsize = ival * sizeof(int);//case label must be constant expression.  
            break;
        case jval:
            bufsize = jval * sizeof(int);
            break;
        case kval:
            bufsize = kval * sizeof(int);
            break;
    }
```  

#### 5.14 Write a program to read strings from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example, if the input is  

```
how now now now brown cow cow
```

#### the output should indicate that the word now occurred three times.  

[ex5_14.cpp](./ex5_14.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_14.cpp
➜  ch05 git:(master) ✗ ./a.out
how now now now brown cow cow
the word 'now' occurred 3 times
```  

#### 5.15 Explain each of the following loops. Correct any problems you detect.  

```
(a) for (int ix = 0; ix != sz; ++ix) { /* . . . */ }
if (ix != sz)
// . . .
(b) int ix;
for (ix != sz; ++ix) { /* . . . */ }
(c) for (int ix = 0; ix != sz; ++ix, ++ sz) { /* . . . */ }
``` 

```
(a) int ix;
    for (ix = 0; ix != sz; ++ix)  { /* ... */ }
    if (ix != sz)
    // . . .
(b) int ix;
    for (; ix != sz; ++ix) { /* ... */ }
(c) for (int ix = 0; ix != sz; ++ix) { /*...*/ }
```  

#### 5.16 The while loop is particularly good at executing while some condition holds; for example, when we need to read values until end-of-file. The for loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could use only one loop, which would you choose? Why?  

```cpp
// while idiomatic
int i;
while ( cin >> i )
    // ...

// same as for
for (int i = 0; cin >> i;)
    // ...

// for idiomatic
for (int i = 0; i != size; ++i)
    // ...

// same as while
int i = 0;
while (i != size)
{
    // ...
    ++i;
}
```

> I prefer for loop.  

#### 5.17 Given two vectors of ints, write a program to determine whether one vector is a prefix of the other. For vectors of unequal length, compare the number of elements of the smaller vector. For example, given the vectors containing 0, 1, 1, and 2 and 0, 1, 1, 2, 3, 5, 8, respectively your program should return true.  

[ex5_17.cpp](./ex5_17.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_17.cpp 
➜  ch05 git:(master) ✗ ./a.out
true
```  

#### 5.18 Explain each of the following loops. Correct any problems you detect.  

```
(a) do // added bracket.
int v1, v2;
cout << "Please enter two numbers to sum:" ;
if (cin >> v1 >> v2)
    cout << "Sum is: " << v1 + v2 << endl;
while (cin);

(b) do {
// . . .
} while (int ival = get_response());// should not declared in this scope.

(c) do {
    int ival = get_response();
} while (ival);// ival is not declared in this scope.
```

#### 5.19 Write a program that uses a do while loop to repetitively request two strings from the user and report which string is less than the other.  

[ex5_19.cpp](./ex5_19.cpp)  


```
➜  ch05 git:(master) ✗ g++ ex5_19.cpp
➜  ch05 git:(master) ✗ ./a.out  
Input two strings: blue
espeon
blue is less than the other. 

More? Enter yes or no: no
```

#### 5.20 Write a program to read a sequence of strings from the standard input until either the same word occurs twice in succession or all the words have been read. Use a while loop to read the text one word at a time. Use the break statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.  

[ex5_20.cpp](./ex5_20.cpp)

```
➜  ch05 git:(master) ✗ g++ ex5_20.cpp
➜  ch05 git:(master) ✗ ./a.out 
espeon espeon
espeon occurs twice in succession.
```  

#### 5.21 Revise the program from the exercise in § 5.5.1 (p. 191) so that it looks only for duplicated words that start with an uppercase letter.  

[ex5_21.cpp](./ex5_21.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_21.cpp
➜  ch05 git:(master) ✗ ./a.out
espeon espeon Espeon Espeon
Espeon occurs twice in succession.
```  

#### 5.22 The last example in this section that jumped back to begin could be better written using a loop. Rewrite the code to eliminate the goto.  

```cpp
// backward jump over an initialized variable definition is okay
begin:
    int sz = get_size();
    if (sz <= 0) {
        goto begin;
    }
```  

Eliminate:  

```cpp
for (int sz = get_size(); sz <=0; sz = get_size())
    ; // should not remove.
```  

#### 5.23 Write a program that reads two integers from the standard input and prints the result of dividing the first number by the second.

[ex5_23.cpp](./ex5_23.cpp)  

```cpp
➜  ch05 git:(master) ✗ g++ ex5_23.cpp
➜  ch05 git:(master) ✗ ./a.out
5
2
2
```  

#### 5.24 Revise your program to throw an exception if the second number is zero. Test your program with a zero input to see what happens on your system if you don’t catch an exception.

[ex5_24.cpp](./ex5_24.cpp)  

```
//5.23
➜  ch05 git:(master) ✗ ./a.out   
2
0
[1]    19382 floating point exception (core dumped)  ./a.out
//5.24
➜  ch05 git:(master) ✗ g++ ex5_24.cpp
➜  ch05 git:(master) ✗ ./a.out
2
0
terminate called after throwing an instance of 'std::runtime_error'
  what():  divisor is zero.
[1]    19427 abort (core dumped)  ./a.out
```  

#### 5.25 Revise your program from the previous exercise to use a try block to catch the exception. The catch clause should print a message to the user and ask them to supply a new number and repeat the code inside the try.  

[ex5_25.cpp](./ex5_25.cpp)  

```
➜  ch05 git:(master) ✗ g++ ex5_25.cpp
➜  ch05 git:(master) ✗ ./a.out
5
0
divisor is zero.
Try Again? Enter y or n:
5
Input two integers: 0
0
divisor is zero.
Try Again? Enter y or n:
y
Input two integers: 5
5
1
Input two integer.
```