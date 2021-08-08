# Chapter 8  


#### 1. Write a function that takes and returns an istream&. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.  

[ex8_01.cpp](./ex8_01.cpp)  

#### 2. Test your function by calling it, passing cin as an argument.  

```
➜  ch08 git:(master) ✗ g++ ex8_01.cpp
➜  ch08 git:(master) ✗ ./a.out
You are mine.  
You
are
mine.
you
you
```  

#### 3. What causes the following while to terminate?  

```cpp
while (cin >> i) /* ...*/
```  

> putting cin in an error state cause to terminate. such as eofbit, failbit and badbit.  

#### 4. Write a function to open a file for input and read its contents into a vector of strings, storing each line as a separate element in the vector.  

[ex8_04.cpp](./ex8_04.cpp)  


```
➜  ch08 git:(master) ✗ g++ ex8_04.cpp
➜  ch08 git:(master) ✗ ./a.out
devil may cry
you've heard of it haven't you?
the legend of sparda
when I was young my father would tell me story about it.
long ago in anicent time
a demon rebel against his own kind 
for the sake of human race.  
```  

#### 5. Rewrite the previous program to store each word in a separate element.  

```
➜  ch08 git:(master) ✗ g++ ex8_05.cpp
➜  ch08 git:(master) ✗ ./a.out
devil may cry you've heard of it haven't you? the legend of sparda when I was young my father would tell me story about it. long ago in anicent time a demon rebel against his own kind for the sake of human race.                      
```  

#### 6. Rewrite the bookstore program from § 7.1.1 (p. 256) to read its transactions from a file. Pass the name of the file as an argument to main (§ 6.2.5, p. 218).  

[ex8_06.cpp](./ex8_06.cpp)  

```
➜  ch08 git:(master) ✗ g++ ex8_06.cpp ../ch07/ex7_26_sales_data.cpp  
➜  ch08 git:(master) ✗ ./a.out ../ch01/book_sales 
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22
```  

#### 7. Revise the bookstore program from the previous section to write its output to a file. Pass the name of that file as a second argument to main.  

[ex8_07.cpp](./ex8_07.cpp)  

```
➜  ch08 git:(master) ✗ g++ ex8_07.cpp ../ch07/ex7_26_sales_data.cpp  
➜  ch08 git:(master) ✗ ./a.out ../ch01/book_sales ex8_07.txt
```  

#### 8. Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure that the data are preserved.  

[ex8_08.cpp](./ex8_08.cpp)  

```
➜  ch08 git:(master) ✗ g++ ex8_08.cpp ../ch07/ex7_26_sales_data.cpp
➜  ch08 git:(master) ✗ ./a.out ../ch01/book_sales ex8_08.txt
➜  ch08 git:(master) ✗ ./a.out ../ch01/book_sales ex8_08.txt
```

We can see:  

```
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22
```

#### 9. Use the function you wrote for the first exercise in § 8.1.2 (p. 314) to print the contents of an istringstream object.  

[ex8_09.cpp](./ex8_09.cpp)  

```
➜  ch08 git:(master) ✗ g++ ex8_09.cpp
➜  ch08 git:(master) ✗ ./a.out
come
here.
```  

#### 10. Write a program to store each line from a file in a vector<string>. Now use an istringstream to read each element from the vector a word at a time.  

[ex8_10.cpp](./ex8_10.cpp)  

```
➜  ch08 git:(master) ✗ g++ ex8_10.cpp
➜  ch08 git:(master) ✗ ./a.out
devil
may
cry
you've
heard
of
it
haven't
you?
the
legend
of
sparda
when
I
was
young
my
father
would
tell
me
story
about
it.
long
ago
in
anicent
time
a
demon
rebel
against
his
own
kind
for
the
sake
of
human
race.
```  

#### 11. The program in this section defined its istringstream object inside the outer while loop. What changes would you need to make if record were defined outside that loop? Rewrite the program, moving the definition of record outside the while, and see whether you thought of all the changes that are needed.  

[ex8_11.cpp](./ex8_11.cpp)  


```
➜  ch08 git:(master) ✗ g++ ex8_11.cpp
➜  ch08 git:(master) ✗ ./a.out
blue 17310
espeon 11000
blue 17310 
espeon 11000 
```  

#### 12. Why didn’t we use in-class initializers in PersonInfo?  

> Cause we need a aggregate class here. so it should have no in-class initializers.  

#### 13. Rewrite the phone number program from this section to read from a named file rather than from cin.
 
[ex8_13.cpp](./ex8_13.cpp)  

```
➜  ch08 git:(master) ✗ g++ ex8_13.cpp
➜  ch08 git:(master) ✗ ./a.out
morgan  201-555-2368 862-555-0123
drew  973-555-0130
lee  609-555-0132 201-555-0175 800-555-0000
```  

#### 14. Why did we declare entry and nums as const auto &?  

+ cause they are all class type, not the built-in type. so reference more effective.
+ output shouldn't change their values. so we added the const.