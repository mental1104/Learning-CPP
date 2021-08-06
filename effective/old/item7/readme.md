# Item 7 Declare destructors virtual in polymorphic base classes.  

## [Without `Virtual` destructor](./without_virtual.cpp)
```cpp
//......................
class base{
public:    
    //.......................
    ~base() { delete []a; }
    //.......................
};

class derive : public base{
public:
    //.......................
    ~derive() { delete []b; }
    //.......................
};

int main(){
    base* temp = new derive();
    delete temp;
    return 0;
}
```
`g++ without_virtual.cpp`  
`valgrind --leak-check=yes ./a.out`  

`g++ -fdump-class-hierarchy without_virtual.cpp`  
> If this does not work, try `g++ -fdump-lang-class without_virtual.cpp` instead.  

From line `4228` we can see: 

```
Class base
   size=8 align=8
   base size=8 base align=8
base (0x0x7f16f2368d80) 0

Class derive
   size=16 align=8
   base size=16 base align=8
derive (0x0x7f16f23667b8) 0
  base (0x0x7f16f1fc3120) 0
```
There's no vtable for both.  


```shell
==460== Memcheck, a memory error detector
==460== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==460== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==460== Command: ./a.out
==460== 
==460== 
==460== HEAP SUMMARY:
==460==     in use at exit: 80 bytes in 1 blocks
==460==   total heap usage: 4 allocs, 3 frees, 72,840 bytes allocated
==460== 
==460== 80 bytes in 1 blocks are definitely lost in loss record 1 of 1
==460==    at 0x483C583: operator new[](unsigned long) (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==460==    by 0x109360: derive::derive() (in /home/espeon/work/effective/a.out)
==460==    by 0x10922C: main (in /home/espeon/work/effective/a.out)
==460== 
==460== LEAK SUMMARY:
==460==    definitely lost: 80 bytes in 1 blocks
==460==    indirectly lost: 0 bytes in 0 blocks
==460==      possibly lost: 0 bytes in 0 blocks
==460==    still reachable: 0 bytes in 0 blocks
==460==         suppressed: 0 bytes in 0 blocks
==460== 
==460== For lists of detected and suppressed errors, rerun with: -s
==460== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
espeon@Espeon:~/work/effective$ 
```  

The lost 80 bytes memory definitely come from the derived class:  
`b = new int[20];`  
This is what we called partially freed memory, undefined behavior.  

---

## [With `Virtual` destructor](./with_virtual.cpp)

```cpp
#include<iostream>

using namespace::std;

class base{
public:    
    //.....................
    virtual ~base() { delete []a; }
    //.....................
};

class derive : public base{
public:
    //.................
    ~derive() { delete []b; }
    //.................
};

int main(){
    base* temp = new derive();
    delete temp;
    return 0;
}
```
`g++ with_virtual.cpp`  
`valgrind --leak-check=yes ./a.out`  
`g++ -fdump-lang-class with_virtual.cpp`  

We can see:  

```
Vtable for base
base::_ZTV4base: 4 entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI4base)
16    (int (*)(...))base::~base
24    (int (*)(...))base::~base

Class base
   size=16 align=8
   base size=16 base align=8
base (0x0x7fd4397bad80) 0
    vptr=((& base::_ZTV4base) + 16)

Vtable for derive
derive::_ZTV6derive: 4 entries
0     (int (*)(...))0
8     (int (*)(...))(& _ZTI6derive)
16    (int (*)(...))derive::~derive
24    (int (*)(...))derive::~derive

Class derive
   size=24 align=8
   base size=24 base align=8
derive (0x0x7fd4397b87b8) 0
    vptr=((& derive::_ZTV6derive) + 16)
  base (0x0x7fd439417180) 0
      primary-for derive (0x0x7fd4397b87b8)
```
Why are there two destructors?  

> The entries for virtual destructors are actually pairs of entries.
The first destructor,
called the complete object destructor,
performs the destruction without calling delete() on the object.
The second destructor,
called the deleting destructor,
calls delete() after destroying the object.
Both destroy any virtual bases;
a separate, non-virtual function,
called the base object destructor,
performs destruction of the object but
not its virtual base subobjects, and does not call delete().


```shell
==470== Memcheck, a memory error detector
==470== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==470== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==470== Command: ./a.out
==470== 
==470== 
==470== HEAP SUMMARY:
==470==     in use at exit: 0 bytes in 0 blocks
==470==   total heap usage: 4 allocs, 4 frees, 72,848 bytes allocated
==470== 
==470== All heap blocks were freed -- no leaks are possible
==470== 
==470== For lists of detected and suppressed errors, rerun with: -s
==470== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Declare two stack variable of base and derive, we can feel that vptr does exist:  

```cpp
base b;
derive d;
cout << "Size of base:  " << sizeof(b) << "\n" 
    << "Size of derive: " << sizeof(d) << endl;
```
Output:  
```shell
Size of base:  16 (vptr + pointer a )
Size of derive: 24 (vptr + pointer a + b)
```