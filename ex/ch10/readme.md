# Chapter 10 Generic Algorithm  
## Note
### Stream iterator  

#### istream_iterator

```cpp
#include<iostream>
#include<numeric>
#include<iterator>

using namespace::std;

int main(){
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0) << endl;
    return 0;
}
```  

```
10 20 30 40 50 60 70 80 90 100 Ctrl-D
550
```

#### ostream_iterator  

```cpp
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    ostream_iterator<int> out(cout, "-");
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}
```


## Exercise 

#### 10.1 The algorithm header defines a function named count that, like find, takes a pair of iterators and a value. count returns a count of how often that value appears. Read a sequence of ints into a vector and print the count of how many elements have a given value.  

[ex10_01.cpp](./ex10_01.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_1.cpp
➜  ch10 git:(master) ✗ ./a.out
8
```  

#### 10.2 Repeat the previous program, but read values into a list of strings.  

[ex10_02.cpp](./ex10_02.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_2.cpp
➜  ch10 git:(master) ✗ ./a.out
4
```  

#### 10.3 Use accumulate to sum the elements in a vector<int>.  

[ex10_03.cpp](./ex10_03.cpp)   

```
➜  ch10 git:(master) ✗ g++ ex10_3.cpp
➜  ch10 git:(master) ✗ ./a.out
50
```  

#### 10.4 Assuming v is a vector<double>, what, if anything, is wrong with calling accumulate(v.cbegin(), v.cend(), 0)?  

[ex10_04.cpp](./ex10_04.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_4.cpp
➜  ch10 git:(master) ✗ ./a.out
15
```  

#### 10.5 In the call to equal on rosters, what would happen if both rosters held C-style strings, rather than library strings?  

[ex10_05.cpp](./ex10_05.cpp)  

> using relational operators is just comparison between the address of two c-style strings but not their values.  

#### 10.6 Using fill_n, write a program to set a sequence of int values to 0.  

[ex10_06.cpp](./ex10_06.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_06.cpp
➜  ch10 git:(master) ✗ ./a.out
0 0 0 0 0 0 0 0 0 0 
```  

#### 10.7 Determine if there are any errors in the following programs and, if so, correct the error(s):  

(a) 
```cpp
vector<int> vec; list<int> lst; int i;
while (cin >> i)
    lst.push_back(i);
//vec.resize(lst.size())//we should manually change its size.  
copy(lst.cbegin(), lst.cend(), vec.begin());
```
(b) 
```cpp
vector<int> vec;
vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
// Fixed: 1. use `v.resize(10);`
//    or  2. use `fill_n(std::back_inserter(v), 10, 0)`
fill_n(vec.begin(), 10, 0);
```  

#### 10.8 We said that algorithms do not change the size of the containers over which they operate. Why doesn’t the use of back_inserter invalidate this claim?  

> Cause the back_inserter is a insert iterator, what iterator adaptor that generates an iterator that uses a container operation to add elements to a given container.  

#### 10.9 Implement your own version of elimDups. Test your program by printing the vector after you read the input, after the call to unique, and after the call to erase.  

[ex10_09.cpp](./ex10_09.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_09.cpp
➜  ch10 git:(master) ✗ ./a.out
dante nero nico sparda vergil 
```  

#### 10.10 Why do you think the algorithms don’t change the size of containers?  

> Cause the library algorithms operate on iterators, not containers. Thus, an algorithm cannot (directly) add or remove elements.  

#### 10.11 Write a program that uses stable_sort and isShorter to sort a vector passed to your version of elimDups. Print the vector to verify that your program is correct.  

[ex10_11.cpp](./ex10_11.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_11.cpp
➜  ch10 git:(master) ✗ ./a.out
by fa he oh so You shall die  My power shall be absolute 
```  

#### 10.12 Write a function named compareIsbn that compares the isbn() members of two Sales_data objects. Use that function to sort a vector that holds Sales_data objects.  

[ex10_12.cpp](./ex10_12.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_12.cpp
➜  ch10 git:(master) ✗ ./a.out
AwesomeCPP CppCore CppPrimer JavaCore PythonCookBook 
```

#### 10.13 The library defines an algorithm named partition that takes a predicate and partitions the container so that values for which the predicate is true appear in the first part and those for which the predicate is false appear in the second part. The algorithm returns an iterator just past the last element for which the predicate returned true. Write a function that takes a string and returns a bool indicating whether the string has five characters or more. Use that function to partition words. Print the elements that have five or more characters.  

[ex10_13.cpp](./ex10_13.cpp)  


```
➜  ch10 git:(master) ✗ g++ ex10_13.cpp
➜  ch10 git:(master) ✗ ./a.out
vergil trish dante sparda 
```  

#### 10.14 Write a lambda that takes two ints and returns their sum.  

```cpp
auto add = [](int lhs, int rhs){return lhs + rhs;};
```

#### 10.15 Write a lambda that captures an int from its enclosing function and takes an int parameter. The lambda should return the sum of the captured int and the int parameter.  

```cpp
int i = 42;
auto add = [i](int num){return i + num;};
```  

#### 10.16 Write your own version of the biggies function using lambdas.  

[ex10_16.cpp](./ex10_16.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_16.cpp
➜  ch10 git:(master) ✗ ./a.out
ex10.16: hi~ 1234 alan 
```  

#### 10.17 Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the call to sort instead of the compareIsbn function.  

Compared with [ex10_12.cpp](./ex10_12.cpp)    

[ex10_17.cpp](./ex10_17.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_17.cpp
➜  ch10 git:(master) ✗ ./a.out
AwesomeCPP CppCore CppPrimer JavaCore PythonCookBook 
```

#### 10.18 Rewrite biggies to use partition instead of find_if. We described the partition algorithm in exercise 10.13 in § 10.3.1 (p. 387).  

[ex10_18.cpp](./ex10_18.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_18.cpp
➜  ch10 git:(master) ✗ ./a.out
ex10.18: hi~ 1234 alan 
```  

#### 10.19 Rewrite the previous exercise to use stable_partition, which like stable_sort maintains the original element order in the paritioned sequence.  

[ex10_19.cpp](./ex10_19.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_19.cpp
➜  ch10 git:(master) ✗ ./a.out
ex10.18: hi~ 1234 alan 
```  

#### 10.20 The library defines an algorithm named count_if. Like find_if, this function takes a pair of iterators denoting an input range and a predicate that it applies to each element in the given range. count_if returns a count of how often the predicate is true. Use count_if to rewrite the portion of our program that counted how many words are greater than length 6.  

[ex10_20.cpp](./ex10_20.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_20.cpp
➜  ch10 git:(master) ✗ ./a.out
2
```  

#### 10.21 Write a lambda that captures a local int variable and decrements that variable until it reaches 0. Once the variable is 0 additional calls should no longer decrement the variable. The lambda should return a bool that indicates whether the captured variable is 0.  

[ex10_21.cpp](./ex10_21.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_21.cpp
➜  ch10 git:(master) ✗ ./a.out
6
5
4
3
2
1
0
```  

#### 10.22 Rewrite the program to count words of size 6 or less using functions in place of the lambdas.  

[ex10_22.cpp](./ex10_22.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_22.cpp
➜  ch10 git:(master) ✗ ./a.out
1
```  

#### 10.23 How many arguments does bind take?  

> Assuming the function to be bound have n parameters, bind take n + 1 parameters. The additional one is for the function to be bind itself.  

#### 10.24 Use bind and check_size to find the first element in a vector of ints that has a value greater than the length of a specified string value.  

[ex10_24.cpp](./ex10_24.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_24.cpp
➜  ch10 git:(master) ✗ ./a.out
5
```  

#### 10.25 In the exercises for § 10.3.2 (p. 392) you wrote a version of biggies that uses partition. Rewrite that function to use check_size and bind.  

[ex10_25.cpp](./ex10_25.cpp)  


```
➜  ch10 git:(master) ✗ g++ ex10_25.cpp
➜  ch10 git:(master) ✗ ./a.out
jumps over quick slow turtle 
```  

#### 10.26 Explain the differences among the three kinds of insert iterators.  

+ back_inserter uses push_back.
+ front_inserter uses push_front.
+ insert uses insert >This function takes a second argument, which must be an iterator into the given container. Elements are inserted ahead of the element denoted by the given iterator.


#### 10.27 In addition to unique (§ 10.2.3, p. 384), the library defines function named unique_copy that takes a third iterator denoting a destination into which to copy the unique elements. Write a program that uses unique_copy to copy the unique elements from a vector into an initially empty list.  

[ex10_27.cpp](./ex10_27.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_27.cpp
➜  ch10 git:(master) ✗ ./a.out
1 3 5 7 9 
```  

#### 10.28 Copy a vector that holds the values from 1 to 9 inclusive, into three other containers. Use an inserter, a back_inserter, and a front_inserter, respectivly to add elements to these containers. Predict how the output sequence varies by the kind of inserter and verify your predictions by running your programs.  

[ex10_28.cpp](./ex10_28.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_28.cpp
➜  ch10 git:(master) ✗ ./a.out
inserter v1: 1 2 3 4 5 6 7 8 9 
back_inserter v2: 1 2 3 4 5 6 7 8 9 
front_inserter d: 9 8 7 6 5 4 3 2 1 
```

#### 10.29 Write a program using stream iterators to read a text file into a vector of strings.  

[ex10_29.cpp](./ex10_29.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_29.cpp
➜  ch10 git:(master) ✗ ./a.out
devil may cry you've heard of it haven't you? the legend of sparda when I was young my father would tell me story about it. long ago in anicent time a demon rebel against his own kind for the sake of human race. 
```

#### 10.30 Use stream iterators, sort, and copy to read a sequence of integers from the standard input, sort them, and then write them back to the standard output.  

[ex10_30.cpp](./ex10_30.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_30.cpp
➜  ch10 git:(master) ✗ ./a.out
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10 
```  

#### 10.31 Update the program from the previous exercise so that it prints only the unique elements. Your program should use unqiue_copy (§ 10.4.1, p. 403).  

[ex10_31.cpp](./ex10_31.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_31.cpp
➜  ch10 git:(master) ✗ ./a.out
1 2 3 4 5 5 5 6 7 8 9 0 0 0 
0 1 2 3 4 5 6 7 8 9 
```  

#### 10.32 Rewrite the bookstore problem from § 1.6 (p. 24) using a vector to hold the transactions and various algorithms to do the processing. Use sort with your compareIsbn function from § 10.3.1 (p. 387) to arrange the transactions in order, and then use find and accumulate to do the sum.  

[ex10_32.cpp](./ex10_32.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_32.cpp 
➜  ch10 git:(master) ✗ ./a.out
11111
1
11
11111
1
11
11111 2 22 11
```  

#### 10.33 Write a program that takes the names of an input file and two output files. The input file should hold integers. Using an istream_iterator read the input file. Using ostream_iterators, write the odd numbers into the first output file. Each value should be followed by a space. Write the even numbers into the second file. Each of these values should be placed on a separate line.  

[ex10_33.cpp](./ex10_33.cpp)  


```
➜  ch10 git:(master) ✗ g++ ex10_33.cpp
➜  ch10 git:(master) ✗ ./a.out
```

[num.txt](./num.txt)  
[odd.txt](./odd.txt)  
[even.txt](./even.txt)  

#### 18.34 Use reverse_iterators to print a vector in reverse order.  

[ex10_34.cpp](./ex10_34.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_34.cpp
➜  ch10 git:(master) ✗ ./a.out
100 9 8 7 6 5 4 3 2 1 
```  

#### 18.35 Now print the elements in reverse order using ordinary iterators.  

[ex10_35.cpp](./ex10_35.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_35.cpp
➜  ch10 git:(master) ✗ ./a.out
100 9 8 7 6 5 4 3 2 1 
```  

#### 18.36 Use find to find the last element in a list of ints with value 0.  

[ex10_36.cpp](./ex10_36.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_36.cpp
➜  ch10 git:(master) ✗ ./a.out
0
```  

##### 18.37 Given a vector that has ten elements, copy the elements from positions 3 through 7 in reverse order to a list.  

[ex10_37.cpp](./ex10_37.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_37.cpp
➜  ch10 git:(master) ✗ ./a.out
7 6 5 4 
```  

#### 18.38 List the five iterator categories and the operations that each supports.  

+ Input iterators : ==, !=, ++, *, ->
+ Output iterators : ++, *
+ Forward iterators : ==, !=, ++, *, ->
+ Bidirectional iterators : ==, !=, ++, --, *, ->
+ Random-access iterators : ==, !=, <, <=, >, >=, ++, --, +, +=, -, -=, -(two iterators), *, ->, iter[n] == * (iter + n)  

#### 18.39 What kind of iterator does a list have? What about a vector?  

> list have the Bidirectional iterators. vector have the Random-access iterators.  

#### 18.40 What kinds of iterators do you think copy requires? What about reverse or unique?  

+ copy : first and second are Input iterators, last is Output iterators.
+ reverse : Bidirectional iterators.
+ unique : Forward iterators.  

#### 18.41 Based only on the algorithm and argument names, describe the operation that the each of the following library algorithms performs:  

```cpp
replace(beg, end, old_val, new_val); // replace the old_elements in the input range as new_elements.
replace_if(beg, end, pred, new_val); // replace the elements in the input range which pred is true as new_elements.
replace_copy(beg, end, dest, old_val, new_val); // copy the new_elements which is old_elements in the input range into dest.
replace_copy_if(beg, end, dest, pred, new_val); // copy the new_elements which pred is true in the input range into dest.
```  

#### 18.42 Reimplement the program that eliminated duplicate words that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.

[ex18_42.cpp](./ex18_42.cpp)  

```
➜  ch10 git:(master) ✗ g++ ex10_42.cpp
➜  ch10 git:(master) ✗ ./a.out
aa aasss 
```  


