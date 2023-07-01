# Chapter 9 Sequential Containers  

## Note

Vector's max size: 
```cpp
//ubuntu 20-04 g++ 9.3.0
#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec;
    cout << vec.max_size() << endl;
    return 0;
}
```

```
➜  ch09 git:(master) ✗ g++ maxsize.cpp
➜  ch09 git:(master) ✗ ./a.out
2305843009213693951
```


## Exercise

#### 9.1 Which is the most appropriate—a vector, a deque, or a list—for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.  

(a) Read a fixed number of words, inserting them in the container alphabetically
as they are entered. We’ll see in the next chapter that associative containers are better
suited to this problem.

> list  

(b) Read an unknown number of words. Always insert new words at the back.
Remove the next value from the front.  

> deque  

(c) Read an unknown number of integers from a file. Sort the numbers and then
print them to standard output.  

> vector  

#### 9.2 Define a list that holds elements that are deques that hold ints.  

```cpp
list<deque<int>>
```

#### 9.3 What are the constraints on the iterators that form iterator ranges?  

+ they refer to elements of the same container.
+ It is possible to reach end by repeatedly incrementing begin.  

#### 9.4 Write a function that takes a pair of iterators to a vector<int> and an int value. Look for that value in the range and return a bool indicating whether it was found.  

```cpp
bool func(vector<int>::iterator begin, vector<int>::iterator end, int value){
    for(; begin!=end; ++begin){
        if(*first == value)
            return true;
    }
    return false;
}  
```

#### 9.5 Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.  

```cpp
vector<int>::iterator func(vector<int>::iterator begin, vector<int>::iterator end, int value){
    for(; begin!=end; ++begin){
        if(*first == value)
            break;
    }
    return begin;
}  
```

#### 9.6 What is wrong with the following program? How might you correct it?  

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
iter2 = lst1.end();
while (iter1 < iter2) /* ...
*/
```

```cpp
while(iter1 != iter2)
```  

> operator < is not implemented in std::list, because std::list is essetially a doubly linked list. Addresses of nodes of linked list are not necessarily continuous.

#### 9.7 What type should be used as the index into a vector of ints?  

> vector<int>::size_type 

#### 9.8 What type should be used to read elements in a list of strings? To write them?  

```cpp
list<string>::const_iterator // to read
list<string>::iterator // to write
```  

#### 9.9 What is the difference between the begin and cbegin functions?  

+ cbegin is a const member that returns the container’s const_iterator type.

+ begin is nonconst and returns the container’s iterator type.  

#### 9.10 What are the types of the following four objects?  

```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```  

```
vector<int>::iterator it1;
vector<int>::const_iterator it2;  
vector<int>::const_iterator it3;
vector<int>::const_iteratpr it4;
```

#### 9.11 Show an example of each of the six ways to create and initialize a vector. Explain what values each vector contains.  

```cpp
vector<int> vec;    // vec is empty
vector<int> vec(10);    // 0
vector<int> vec(10, 1);  // 1
vector<int> vec{ 1, 2, 3, 4, 5 }; // 1, 2, 3, 4, 5
vector<int> vec(other_vec); // same as other_vec
vector<int> vec(other_vec.begin(), other_vec.end()); // same as other_vec
```  

#### 9.12 Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.  

> The constructor that takes another container as an argument (excepting array) assumes the container type and element type of both containers are identical. It will also copy all the elements of the received container into the new one:

```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers);      // error: no matching function for call...
list<double> numbers4(numbers);     // error: no matching function for call...
```  

> **The constructor that takes two iterators as arguments does not require the container types to be identical.** Moreover, the element types in the new and original containers can differ as long as it is possible to convert the elements we’re copying to the element type of the container we are initializing. It will also copy only the object delimited by the received iterators.  

```cpp
list<int> numbers = { 1, 2, 3, 4, 5 };
list<int> numbers2(numbers.begin(), numbers.end);        // ok, numbers2 has the same elements as numbers
vector<int> numbers3(numbers.begin(), --numbers.end());  // ok, numbers3 is { 1, 2, 3, 4 }
list<double> numbers4(++numbers.beg(), --numbers.end());        // ok, numbers4 is { 2, 3, 4 }
forward_list<float> numbers5(numbers.begin(), numbers.end());   // ok, number5 is { 1, 2, 3, 4, 5 }
```

#### 9.13 How would you initialize a vector<double> from a list<int>? From a vector<int>? Write code to check your answers.  

[ex9_13.cpp](./ex9_13.cpp)  

```cpp
➜  ch09 git:(master) ✗ g++ ex9_13.cpp
➜  ch09 git:(master) ✗ ./a.out
1 2 3 4 5 6 7 8 9 
1 2 3 4 5 
```  

#### 9.14 Write a program to assign the elements from a list of char* pointers to C-style character strings to a vector of strings.  

[ex9_14.cpp](./ex9_14.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_14.cpp
➜  ch09 git:(master) ✗ ./a.out
vergil vergil vergil vergil vergil vergil vergil vergil vergil vergil 
```  

#### 9.15 Write a program to determine whether two vector<int>s are equal.  

[ex9_15.cpp](./ex9_15.cpp)

```
➜  ch09 git:(master) ✗g++ ex9_15.cpp
➜  ch09 git:(master) ✗ ./a.out
false
true
```  

#### 9.16 Repeat the previous program, but compare elements in a list<int> to a vector<int>.  

```cpp
#include<iostream>
#include<vector>
#include<list>

using namespace::std;

int main(){
    vector<int> a(10,5);
    list<int> b(1,10);
    cout << ((a == b)?"true":"false") << endl;//can 't pass.
    return 0;
}
```

> It can't compile.  

#### 9.17 Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?  

```cpp
if (c1 < c2)
```

> First, there must be the identical container and same type holded. Second, the type held must support relational operator.  

#### 9.18 Write a program to read a sequence of strings from the standard input into a deque. Use iterators to write a loop to print the elements in the deque.  

[ex9_18.cpp](./ex9_18.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_18.cpp
➜  ch09 git:(master) ✗ ./a.out
don't
get
so
cocky
don't get so cocky 
```  

#### 9.19 Rewrite the program from the previous exercise to use a list. List the changes you needed to make.  

[ex9_19.cpp](./ex9_19.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_19.cpp
➜  ch09 git:(master) ✗ ./a.out
string
is
good
string is good 
```  

#### 9.20 Write a program to copy elements from a list<int> into two deques. The even-valued elements should go into one deque and the odd ones into the other.    

[ex9_20.cpp](./ex9_20.cpp)  

```
➜  ch09 git:(master) ✗ mv 9_20.cpp ex9_20.cpp
➜  ch09 git:(master) ✗ g++ ex9_20.cpp
➜  ch09 git:(master) ✗ ./a.out
1 3 5 7 9 
2 4 6 8 10 
```  

#### 9.21 Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.  

```cpp
list<string> lst;
auto iter = lst.begin();
while (cin >> word)
iter = lst.insert(iter, word); // same as calling push_front
```

> It's the same.

#### 9.22 Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?  

```cpp
vector<int>::iterator iter = iv.begin(),
mid = iv.begin() + iv.size()/2;
while (iter != mid)
if (*iter == some_val)
iv.insert(iter, 2 * some_val);
```

+ It's a endless loop. iter never equal mid.
+ mid will be invalid after the insert.  

FIXED:  

```cpp
// cause the reallocation will lead the iterators and references
// after the insertion point to invalid. Thus, we need to call reserver at first.

#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val)
{
    auto mid = [&]{ return v.begin() + v.size() / 2; };
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
}

int main()
{
    std::vector<int> v{ 1, 9, 1, 9, 9, 9, 1, 1 };
    double_and_insert(v, 1);

    for (auto i : v) 
        std::cout << i << std::endl;
}
```

#### 9.23 In the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1?  

```cpp
// check that there are elements before dereferencing an iterator or calling front or back
if (!c.empty()) {
    // val and val2 are copies of the value of the first element in c
    auto val = *c.begin(), val2 = c.front();
    // val3 and val4 are copies of the of the last element in c
    auto last = c.end();
    auto val3 = *(--last); // can’t decrement forward_list iterators
    auto val4 = c.back(); // not supported by forward_list
}
``` 

> same value that equal to the first element's.

#### 9.24 Write a program that fetches the first element in a vector using at, the subscript operator, front, and begin. Test your program on an empty vector.

[ex9_24.cpp](./ex9_24.cpp)  


```
➜  ch09 git:(master) ✗ g++ ex9_24.cpp
➜  ch09 git:(master) ✗ ./a.out
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)
[1]    13568 abort (core dumped)  ./a.out
```  

#### 9.25 In the program on page 349 that erased a range of elements, what happens if elem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are the off-the-end iterator?  

```cpp
list<int> lst = {0,1,2,3,4,5,6,7,8,9};
auto it = lst.begin();
while (it != lst.end())
    if (*it % 2)
    // if the element is odd
        it = lst.erase(it); // erase this element
    else
        ++it;
```

+ if elem1 and elem2 are equal, nothing happened.

+ if elem2 is the off-the-end iterator, it would delete from elem1 to the end.

+ if both elem1 and elem2 are the off-the-end iterator, nothing happened too.

#### 9.26 Using the following definition of ia, copy ia into a vector and into a list. Use the single-iterator form of erase to remove the elements with odd values from your list and the even values from your vector.  

```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```    

[ex9_26.cpp](./ex9_26.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_26.cpp
➜  ch09 git:(master) ✗ ./a.out
list : 0 2 8 
vector : 1 1 3 5 13 21 55 89 
```

#### 9.27 Write a program to find and remove the odd-valued elements in a forward_list<int>.  

[ex9_27.cpp](./ex9_27.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_27.cpp
➜  ch09 git:(master) ✗ ./a.out
2 4 6 8 10 
```  

#### 9.28 Write a function that takes a forward_list<string> and two additional string arguments. The function should find the first string and insert the second immediately following the first. If the first string is not found, then insert the second string at the end of the list.  

[ex9_28.cpp](./ex9_28.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_28.cpp
➜  ch09 git:(master) ✗ ./a.out
Vergil will not cry 
```  

#### 9.29 Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?  

```cpp
vec.resize(100);    // adds 75 elements of value 0 to the back of vec
vec.resize(10);     // erases 90 elements from the back of vec
```  

#### 9.30 What, if any, restrictions does using the version of resize that takes a single argument place on the element type?  

> If the container holds elements of a class type and resize adds elements we must supply an initializer or the element type must have a default constructor.  

#### 9.31 The program on page 354 to remove even-valued elements and duplicate odd ones will not work on a list or forward_list. Why? Revise the program so that it works on these types as well.  

```cpp
vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); // call begin , not cbegin because we’re changing vi
while (iter != vi.end()) {
if (*iter % 2) {
iter = vi.insert(iter, *iter); // duplicate the current element
iter += 2; // advance past this element and the one inserted before it
} else
iter = vi.erase(iter);
// remove even elements
// don’t advance the iterator; iter denotes the element after the one we erased
}
```  
[ex9_31_list.cpp](./ex9_31_list.cpp)  
[ex9_31_forward_list.cpp](./ex9_31_forward_list.cpp)  


```
➜  ch09 git:(master) ✗ g++ ex9_31_list.cpp
➜  ch09 git:(master) ✗ ./a.out 
1 1 3 3 5 5 7 7 9 9 
➜  ch09 git:(master) ✗ g++ ex9_31_forward_list.cpp 
➜  ch09 git:(master) ✗ ./a.out
1 1 3 3 5 5 7 7 9 9 
```

#### 9.32 In the program on page 354 would it be legal to write the call to insert as follows? If not, why not?  

```cpp
iter = vi.insert(iter, *iter++);
```

> the statement is illegal, because as said in Standard [5.2.2] :  

"The order of evaluation of arguments is unspecified."  
As a result, after entering function insert,
iter could be its original value or original value + 1 or even anything else,
depending on how compiler implemented.  

#### 9.33 In the final example in this section what would happen if we did not assign the result of insert to begin? Write a program that omits this assignment to see if your expectation was correct.  

> Crash, because the iterator is invalid after inserting.  

[ex9_33.cpp](./ex9_33.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_33.cpp
➜  ch09 git:(master) ✗ ./a.out
munmap_chunk(): invalid pointer
[1]    16875 abort (core dumped)  ./a.out
```  

#### 9.34 Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following loop. After you’ve analyzed this loop, write a program to test whether your expectations were correct.  

```cpp
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2)
        iter = vi.insert(iter, *iter);
++iter;
```

> "infinite loop". Becasue the `++iter` is outside of the scope of the `while` loop.  

[ex9_34.cpp](./ex9_34.cpp)  



```
➜  ch09 git:(master) ✗ g++ ex9_34.cpp
➜  ch09 git:(master) ✗ ./a.out
0 1 1 2 3 3 4 5 5 6 7 7 8 9 9 
```

#### 9.35 Explain the difference between a vector’s capacity and its size.  

+ The size of a container is the number of elements it already holds;

+ The capacity is how many elements it can hold before more space must be allocated.

#### 9.36 Can a container have a capacity less than its size?  

> No.  

#### 9.37 Why don’t list or array have a capacity member?  

> list does not hold elements contiguously. array has the fixed size statically and neither needs reallocation.  

#### 9.38 Write a program to explore how vectors grow in the library you use.  

[ex9_38.cpp](./ex9_38.cpp)  

> It grows exponentially.  
```
➜  ch09 git:(master) ✗ g++ ex9_38.cpp
➜  ch09 git:(master) ✗ ./a.out
size: 0  capacity: 10
2 3 4 5 6 7 8 9 10
size: 1  capacity: 10
size: 2  capacity: 10
size: 3  capacity: 10
size: 4  capacity: 10
size: 5  capacity: 10
size: 6  capacity: 10
size: 7  capacity: 10
size: 8  capacity: 10
size: 9  capacity: 10
11 12 13 14 15 16 17 18 19 20
size: 10  capacity: 10
size: 11  capacity: 20
size: 12  capacity: 20
size: 13  capacity: 20
size: 14  capacity: 20
size: 15  capacity: 20
size: 16  capacity: 20
size: 17  capacity: 20
size: 18  capacity: 20
size: 19  capacity: 20
11 12 13 14 15 16 17 18 19 20 11 12 13 14 15 16 17 18 19 20
size: 20  capacity: 20
size: 21  capacity: 40
size: 22  capacity: 40
size: 23  capacity: 40
size: 24  capacity: 40
size: 25  capacity: 40
size: 26  capacity: 40
size: 27  capacity: 40
size: 28  capacity: 40
size: 29  capacity: 40
size: 30  capacity: 40
size: 31  capacity: 40
size: 32  capacity: 40
size: 33  capacity: 40
size: 34  capacity: 40
size: 35  capacity: 40
size: 36  capacity: 40
size: 37  capacity: 40
size: 38  capacity: 40
size: 39  capacity: 40
11 12 13 14 15 16 17 18 19 20 11 12 13 14 15 16 17 18 19 20 11 12 13 14 15 16 17 18 19 20 11 12 13 14 15 16 17 18 19 20 11 12 13 14 15 16 17 18 19 20 
size: 40  capacity: 40
size: 41  capacity: 80
size: 42  capacity: 80
size: 43  capacity: 80
size: 44  capacity: 80
size: 45  capacity: 80
size: 46  capacity: 80
size: 47  capacity: 80
size: 48  capacity: 80
size: 49  capacity: 80
size: 50  capacity: 80
size: 51  capacity: 80
size: 52  capacity: 80
size: 53  capacity: 80
size: 54  capacity: 80
size: 55  capacity: 80
size: 56  capacity: 80
size: 57  capacity: 80
size: 58  capacity: 80
size: 59  capacity: 80
size: 60  capacity: 80
size: 61  capacity: 80
size: 62  capacity: 80
size: 63  capacity: 80
size: 64  capacity: 80
size: 65  capacity: 80
size: 66  capacity: 80
size: 67  capacity: 80
size: 68  capacity: 80
size: 69  capacity: 80
size: 70  capacity: 80
size: 71  capacity: 80
size: 72  capacity: 80
size: 73  capacity: 80
size: 74  capacity: 80
size: 75  capacity: 80
size: 76  capacity: 80
size: 77  capacity: 80
size: 78  capacity: 80
size: 79  capacity: 80
size: 80  capacity: 80
size: 81  capacity: 160
size: 82  capacity: 160
size: 83  capacity: 160
size: 84  capacity: 160
size: 85  capacity: 160
size: 86  capacity: 160
size: 87  capacity: 160
size: 88  capacity: 160
size: 89  capacity: 160
```  

#### 9.39 Explain what the following program fragment does:  

```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
    svec.push_back(word);
svec.resize(svec.size()+svec.size()/2);
```  

> The while loop will read words from cin and store them in out vector. Even if we initially reserved 1024 elements, if there are more words read from cin, our vector's capacity will be automatically increased (most implementations will double the previous capacity) to accommodate them.  

#### 9.40 If the program in the previous exercise reads 256 words, what is its likely capacity after it is resized? What if it reads 512? 1,000? 1,048?  

> 512, 1024, 2048, 2000.  


#### 9.41 Write a program that initializes a string from a vector<char>.  

[ex9_41.cpp](./ex9_41.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_41.cpp
➜  ch09 git:(master) ✗ ./a.out
blue
```   

#### 9.42 Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?  

> reserve(200);  

#### 9.43 Write a function that takes three strings, s, oldVal, and newVal. Using iterators, and the insert and erase functions replace all instances of oldVal that appear in s by newVal. Test your function by using it to replace common abbreviations, such as “tho” by ”though” and ”thru” by “through”.  

[ex9_43.cpp](./ex9_43.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_43.cpp
➜  ch09 git:(master) ✗ ./a.out
although you have the power,  though you still need to go through through through it.
```

#### 9.44 Rewrite the previous function using an index and replace.  

[ex9_44.cpp](./ex9_44.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_44.cpp
➜  ch09 git:(master) ✗ ./a.out
Wait a second did you go out tonight? you have to fill me in.
```  

#### 9.45 Write a funtion that takes a string representing a name and two other strings representing a prefix, such as “Mr.” or “Ms.” and a suffix, such as “Jr.” or “III”. Using iterators and the insert and append functions, generate and return a new string with the suffix and prefix added to the given name.

[ex9_45.cpp](./ex9_45.cpp)  
```
➜  ch09 git:(master) ✗ g++ ex9_45.cpp
➜  ch09 git:(master) ✗ ./a.out
Mr.Vergil will never fall
```  

#### 9.46 Rewrite the previous exercise using a position and length to manage the strings. This time use only the insert function.  

[ex9_46.cpp](./ex9_46.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_46.cpp
➜  ch09 git:(master) ✗ ./a.out
Team rocket will never fall.
```  

#### 9.47 Write a program that finds each numeric character and then each alphabetic character in the string "ab2c3d7R4E6". Write two versions of the program. The first should use find_first_of, and the second find_first_not_of.  

[ex9_47.cpp](./ex9_47.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_47.cpp
➜  ch09 git:(master) ✗ ./a.out
numeric characters: 2
3
7
4
6

alphabetic characters: a
b
c
d
R
E
```  

#### 9.48 Given the definitions of name and numbers on page 365, what does numbers.find(name) return?  

```cpp
string numbers("0123456789"), name("r2d2");
```  

[ex9_48.cpp](./ex9_48.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_48.cpp
➜  ch09 git:(master) ✗ ./a.out
8 18446744073709551615
```  

#### 9.49 A letter has an ascender if, as with d or f, part of the letter extends above the middle of the line. A letter has a descender if, as with p or g, part of the letter extends below the line. Write a program that reads a file containing words and reports the longest word that contains neither ascenders nor descenders.

[ex9_49.cpp](./ex9_49.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_49.cpp
➜  ch09 git:(master) ✗ ./a.out
increase
```  

#### 9.50 Write a program to process a vector<string>s whose elements represent integral values. Produce the sum of all the elements in that vector. Change the program so that it sums of strings that represent floating-point values.  

[ex9_50.cpp](./ex9_50.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_50.cpp
➜  ch09 git:(master) ✗ ./a.out
10
10.5
```  

#### 9.51 Write a class that has three unsigned members representing year, month, and day. Write a constructor that takes a string representing a date. Your constructor should handle a variety of date formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.  

[ex9_51.cpp](./ex9_51.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_51.cpp
➜  ch09 git:(master) ✗ ./a.out
day:1 month: 1 year: 1900
```  

#### 9.52 Use a stack to process parenthesized expressions. When you see an open parenthesis, note that it was seen. When you see a close parenthesis after an open parenthesis, pop elements down to and including the open parenthesis off the stack. push a value onto the stack to indicate that a parenthesized expression was replaced.  

[ex9_52a.cpp](./ex9_52a.cpp)  
[ex9_52b.cpp](./ex9_52b.cpp)  

```
➜  ch09 git:(master) ✗ g++ ex9_52.cpp
➜  ch09 git:(master) ✗ ./a.out
This is (noepse).
```