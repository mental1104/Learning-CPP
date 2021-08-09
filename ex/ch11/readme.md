# Chapter 11 Associative Containers  

## Exercise  

#### 11.1 Describe the differences between a map and a vector.   

> map is an associative container whereas vector is a sequence container.  

#### 11.2 Give an example of when each of list, vector, deque, map, and set might be most useful.  

> list : anytime when a doubly-linked list is required.
> vector : anytime when a dynamic array is required.
> deque : when we only need to modify its head and tail.  
> map : dictionary.
> set : when to keep elements sorted and unique.  

#### 11.3 Write your own version of the word-counting program.  

[ex11_3.cpp](./ex11_3.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_3.cpp
➜  ch11 git:(master) ✗ ./a.out
return return return return return re re re re o
o occurs 1 times. 
re occurs 4 times. 
return occurs 5 times. 
```  
#### 11.4 Extend your program to ignore case and punctuation. For example, “example.” “example,” and “Example” should all increment the same counter.  

> see [ex11_3.cpp](./ex11_3.cpp)    

#### 11.5 Explain the difference between a map and a set. When might you use one or the other?  

[see this](http://stackoverflow.com/questions/16286714/advantages-of-stdset-vs-vectors-or-maps)  

> Both std::set and std::map are associative containers. The difference is that std::sets contain only the key, while in std::map there is an associated value. Choosing one over the other depends mainly on what the task at hand is. If you want to build a dictionary of all the words that appear in a text, you could use a std::set<std::string>, but if you also want to count how many times each word appeared (i.e. associate a value to the key) then you would need an std::map<std::string,int>. If you don't need to associate that count, it does not make sense to have the int that is unnecessary.  

#### 11.6 Explain the difference between a set and a list. When might you use one or the other?  

List

+ Searching (linear time).
+ Inserting, deleting, moving (takes constant time).
+ Elements may be ordered.
+ Elements may be sorted.
+ Elements may be duplicate.

Set

+ Searching (logarithmic in size).
+ Insert and delete (logarithimic in general).
+ Elements are un-ordered.
+ Elements are always sorted from lower to higher.
+ Elements are unique.

#### 11.7 Define a map for which the key is the family’s last name and the value is a vector of the children’s names. Write code to add new families and to add new children to an existing family.  

[ex11_7.cpp](./ex11_7.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_7.cpp
➜  ch11 git:(master) ✗ ./a.out
Please ENTER lastname.
sparda
Please ENTER Child's Name.
vergil
dante
nero
Please ENTER lastname.
sparda:
vergil dante nero 
```  

#### 11.8 Write a program that stores the excluded words in a vector instead of in a set. What are the advantages to using a set?  

[ex11_8.cpp](./ex11_8.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_8.cpp
➜  ch11 git:(master) ✗ ./a.out
aa
excluded!
bb
excluded!
cc
excluded!
ccc
ddd
aa bb cc ccc ddd 
```

#### 11.9 Define a map that associates words with a list of line numbers on which the word might occur.  

```cpp
map<string, list<size_t>> m;
```  

#### 11.10 Could we define a map from vector<int>::iterator to int? What about from list<int>::iterator to int? In each case, if not, why not?  

+ vector<int>::iterator to int is ok , because < is defined
+ list<int>::iterator to int is not ok, as no < is defined.  

#### 11.11 Redefine bookstore without using decltype.  

[ex11_11.cpp](./ex11_11.cpp)    

#### 11.12 Write a program to read a sequence of strings and ints, storing each into a pair. Store the pairs in a vector.  

[ex11_12.cpp](./ex11_12.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_12.cpp
➜  ch11 git:(master) ✗ ./a.out
you 1 he 2 she 3 it 4
you : 1
he : 2
she : 3
it : 4
```  

#### 11.13 There are at least three ways to create the pairs in the program for the previous exercise. Write three versions of that program, creating the pairs in each way. Explain which form you think is easiest to write and understand, and why.  

```cpp
// vec.push_back(std::make_pair(str, i));  
// vec.push_back({str, i});  
// vec.emplace_back(str, i); //!!! easiest way.  
```

#### 11.14 Extend the map of children to their family name that you wrote for the exercises in § 11.2.1 (p. 424) by having the vector store a pair that holds a child’s name and birthday.  

[ex11_14.cpp](./ex11_14.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_14.cpp
➜  ch11 git:(master) ✗ ./a.out
Please enter last name, first name and birthday:
vergil sparda 11/14/2000
Please enter last name, first name and birthday:
dante sparda 11/15/2020
Please enter last name, first name and birthday:
nero sparda 10/10/1010
Please enter last name, first name and birthday:
dante:
sparda 11/15/2020

nero:
sparda 10/10/1010

vergil:
sparda 11/14/2000
```

#### 11.15 What are the mapped_type, key_type, and value_type of a map from int to vector<int>?  

+ mapped_type : vector< int >
+ key_type : int
+ value_type : std::pair<const int, vector<int>>  

#### 11.16 Using a map iterator write an expression that assigns a value to an element.   

[ex11_16.cpp](./ex11_16.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_16.cpp
➜  ch11 git:(master) ✗ ./a.out
vergil
vergil
```  

#### 11.17 Assuming c is a multiset of strings and v is a vector of strings, explain the following calls. Indicate whether each call is legal:  

```cpp
copy(v.begin(), v.end(), inserter(c, c.end())); // legal
copy(v.begin(), v.end(), back_inserter(c)); // illegal, no `push_back` in `set`.
copy(c.begin(), c.end(), inserter(v, v.end())); // legal.
copy(c.begin(), c.end(), back_inserter(v)); // legal.
```

#### 11.18 Write the type of map_it from the loop on page 430 without using auto or decltype.  

```cpp
// get an iterator positioned on the first element
auto map_it = word_count.cbegin();
// compare the current iterator to the off-the-end iterator
while (map_it != word_count.cend()) {
    // dereference the iterator to print the element key--value pairs
    cout << map_it->first << " occurs "
        << map_it->second << " times" << endl;
    ++map_it; // increment the iterator to denote the next element
}
```

```cpp
std::map<std::string, size_t>::const_iterator;
```

#### 11.19 Define a variable that you initialize by calling begin() on the multiset named bookstore from § 11.2.2 (p. 425). Write the variable’s type without using auto or decltype.  

```cpp
using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
std::multiset<Sales_data, compareType> bookstore(compareIsbn);
std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
```  

#### 11.20 Rewrite the word-counting program from § 11.1 (p. 421) to use insert instead of subscripting. Which program do you think is easier to write and read? Explain your reasoning.  

[ex11_20.cpp](./ex11_20.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_20.cpp
➜  ch11 git:(master) ✗ ./a.out
return return a b c d e f g h i j
a 1 time
b 1 time
c 1 time
d 1 time
e 1 time
f 1 time
g 1 time
h 1 time
i 1 time
j 1 time
return 2 times
```  

#### 11.21 Assuming word_count is a map from string to size_t and word is a string, explain the following loop:  

```cpp
while (cin >> word)
    ++word_count.insert({word, 0}).first->second;
```  

```
while reading into word
    if word_count has key word:
        word_count[word] += 1
    else:
        word_count[word] = 0
        word_count[word] += 1
```  

#### 11.22 Given a map<string, vector<int>>, write the types used as an argument and as the return value for the version of insert that inserts one element.  

```cpp
std::pair<std::string, std::vector<int>>    // argument
std::pair<std::map<std::string, std::vector<int>>::iterator, bool> // return
```  

#### 11.23 Rewrite the map that stored vectors of children’s names with a key that is the family last name for the exercises in § 11.2.1 (p. 424) to use a multimap.  

[ex11_23.cpp](./ex11_23.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_23.cpp
➜  ch11 git:(master) ✗ ./a.out
sparda vergil
sparda dante
sparda nero
vergil sparda
dante sparda
nero sparda
```

#### 11.24 What does the following program do?  

```cpp
map<int, int> m;
m[0] = 1;
```

> add a key-value pair { 0, 1 } into the map.  

#### 11.25 Contrast the following program with the one in the previous exercise.  

```cpp
vector<int> v;
v[0] = 1;
```  

> UB, since it's trying to dereference an item out of range.  

#### 11.26 What type can be used to subscript a map? What type does the subscript operator return? Give a concrete example—that is, define a map and then write the types that can be used to subscript the map and the type that would be returned from the subscript operator.  

[ex11_26.cpp](./ex11_26.cpp)  


```
➜  ch11 git:(master) ✗ g++ ex11_26.cpp
➜  ch11 git:(master) ✗ ./a.out
type to subscript: i
returned from the subscript operator: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
```

#### 11.27 What kinds of problems would you use count to solve? When might you use find instead?  

> I would use count to deal with multimap or multi multiset.  

> As for the associative container that have unique key, I would use find instead of count.  

#### 11.28 Define and initialize a variable to hold the result of calling find on a map from string to vector of int.  

```cpp
std::map<std::string, std::vector<int>> m{ { "Alan",{ 1,2,3,4,5, } },{ "John",{ 1,5,6,7,8 } } };
```  

#### 11.29 What do upper_bound, lower_bound, and equal_range return when you pass them a key that is not in the container?  

> If the element is not in the multimap, then lower_bound and upper_bound will return equal iterators; both will refer to the point at which the key can be inserted without disrupting the order.

> If no matching element is found, then both the first and second iterators refer to the position where this key can be inserted.  

#### 11.30 Explain the meaning of the operand pos.first->second used in the output expression of the final program in this section.

```
pos                     a pair
pos.first               the iterator refering to the first element with the matching key
pos.first->second       the value part of the key-value of the first element with the matching key
```  

> see 11.21  

#### 11.31 Write a program that defines a multimap of authors and their works. Use find to find an element in the multimap and erase that element. Be sure your program works correctly if the element you look for is not in the map.

[ex11_31.cpp](./ex11_31.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_31.cpp
➜  ch11 git:(master) ✗ ./a.out
alan DMA
alan CLRS
pezy LeetCode
wang FTP
wang CPP-Concurrency
```   

#### 11.32 Using the multimap from the previous exercise, write a program to print the list of authors and their works alphabetically.  

[ex11_32.cpp](./ex11_32.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_32.cpp
➜  ch11 git:(master) ✗ ./a.out
alan: CLRS DMA 
pezy: CP5 LeetCode 
wang: CPP-Concurrency FTP 
```  

#### 11.33 Implement your own version of the word-transformation program.  

[ex11_33.cpp](./ex11_33.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_33.cpp
➜  ch11 git:(master) ✗ ./a.out
where r u 
y dont u send me a pic 
k thk l8r 
```  

#### 11.34 What would happen if we used the subscript operator instead of find in the transform function?  

```cpp
const string& transform(const string &s, const map<string, string> &m)
{
    return m[s];
}
```

> The above code won't compile because the subscript operator might insert an element

#### 11.35 In buildMap, what effect, if any, would there be from rewriting  

```cpp
trans_map[key] = value.substr(1);
```  
#### as trans_map.insert({key, value.substr(1)})?  

+ use subscript operator: if a word does appear multiple times, our loops will put the last corresponding phrase into trans_map
+ use insert: if a word does appear multiple times, our loops will put the first corresponding phrase into trans_map

#### 11.36 Our program does no checking on the validity of either input file. Inparticular, it assumes that the rules in the transformation file are all sensible. What would happen if a line in that file has a key, one space, and then the end of the line? Predict the behavior and then check it against your version of the program.  

> If so, a key-value pair will be {key, " "}(" ".size() !> 1), which cannot be added into the map. As a result, the key would not be replaced with any string.  

#### 11.37 What are the advantages of an unordered container as compared to the ordered version of that container? What are the advantages of the ordered version?  

> [see this for detail](http://www.cs.fsu.edu/~lacher/courses/COP4531/fall13/lectures/containers2/slide04.html)  

#### 11.38 Rewrite the word-counting (§ 11.1, p. 421) and word-transformation(§ 11.3.6, p. 440) programs to use an unordered_map.  

[ex11_38.cpp](./ex11_38.cpp)  

```
➜  ch11 git:(master) ✗ g++ ex11_38.cpp
➜  ch11 git:(master) ✗ ./a.out
where are you 
why dont you send me a picture 
okay? thanks! later 
```