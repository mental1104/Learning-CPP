# Chapter 13 Copy-Control  

## Note  

[memberwise-copy/bitwise-copy](https://stackoverflow.com/questions/42749439/what-is-the-difference-between-memberwise-copy-bitwise-copy-shallow-copy-and-d#)  

[value-like-HasPtr](./ex13_22.h)  
[pointer-like-HasPtr](./ex13_27.h)   


## Exercise  

#### 13.1 What is a copy constructor? When is it used?   

> A copy constructor is a constructor which first parameter is a reference to the class type and any additional parameters have default values.  

+ **Define variables** using an =
+ Pass an object as an argument to a parameter of non-reference type
+ Return an object from a function that has a non-reference return type
+ Brace initialize the elements in an array or the members of an aggregate class
+ Some class types also use copy initialization for the objects they allocate.  

#### 13.2 Explain why the following declaration is illegal:  

```cpp
Sales_data::Sales_data(Sales_data rhs);
```  

> since `rhs` is not a reference.  

```cpp
#include<iostream>

class Test{
public:
    Test(){}
    Test(Test rhs){}
private:
    int temp;
};

int main(){
    Test A;
    Test B(A);
    return 0;
}
``` 

```
➜  ch13 git:(master) ✗ g++ ex13_02.cpp
ex13_02.cpp:6:18: error: invalid constructor; you probably meant ‘Test (const Test&)’
    6 |     Test(Test rhs){}
      |                  ^
```  

#### 13.3 What happens when we copy a StrBlob? What about StrBlobPtrs?  

> when we copy a StrBlob, the shared_ptr member's use_count add one.

> when we copy a StrBlobPrts, the weak_ptr member's use_count isn't changed.(cause the count belongs to shared_ptr)  

#### 13.4 Assuming Point is a class type with a public copy constructor, identify each use of the copy constructor in this program fragment:  

```cpp
Point global;
Point foo_bar(Point arg)//1
{
    Point local = arg, *heap = new Point(global);//2, 3
    *heap = local;
    Point pa[ 4 ] = { local, *heap };//4, 5
    return *heap;//6
}
```  

#### 13.5 Given the following sketch of a class, write a copy constructor that copies all the members. Your constructor should dynamically allocate a new string (§ 12.1.2, p. 458) and copy the object to which ps points, rather than copying ps itself.  

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
private:
    std::string *ps;
    int i;
};
```

```cpp
HasPtr(const HasPtr& rhs):ps(new std::string(*rhs.ps)
), i(rhs.i){}
```  

#### 13.6 What is a copy-assignment operator? When is this operator used? What does the synthesized copy-assignment operator do? When is it synthesized?


> The copy-assignment operator is function named operator=.

> This operator is used when assignment occurred.

> The synthesized copy-assignment operator assigns each non-static member of the right-hand object to corresponding member of the left-hand object using the copy-assignment operator for the type of that member.

> It is synthesized when the class does not define its own.


#### 13.7 What happens when we assign one StrBlob to another? What about StrBlobPtrs?  

> In both cases, shallow copy will happen. All pointers point to the same address since they use the synthesized edition. The use_count changed the same as 13.3.  

#### 13.8 Write the assignment operator for the HasPtr class from exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your assignment operator should copy the object to which ps points.  

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
private:
    std::string *ps;
    int i;
};
```

```cpp
HasPtr& operator=(const HasPtr& rhs){
    std::string* temp = new std::string(*rhs.ps);
    delete ps;
    ps = temp;
    this.i = rhs.i;
    return *this;
}  
```  

#### 13.9 What is a destructor? What does the synthesized destructor do? When is a destructor synthesized?  

> The destructor is a member function with the name of the class prefixed by a tilde(~).

> As with the copy constructor and the copy-assignment operator, for some classes, the synthesized destructor is defined to disallow objects of the type from being destroyed. Otherwise, the synthesized destructor has an empty function body.

> The compiler defines a synthesized destructor for any class that does not define its own destructor.  

#### 13.10 What happens when a StrBlob object is destroyed? What about a StrBlobPtr?  

> When a StrBlob object destroyed, the use_count of the dynamic object will decrement. It will be freed if no shared_ptr to that dynamic object.(shared_ptr)

> When a StrBlobPter object is destroyed the object dynamically allocated will not be freed.(weak_ptr)  

#### 13.11 Add a destructor to your HasPtr class from the previous exercises.  

```cpp
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
private:
    std::string *ps;
    int i;
};
```

```cpp
~HasPtr(){
    delete ps;
    ps = nullptr;
}
```  

#### 13.12 How many destructor calls occur in the following code fragment?  

```cpp
bool fcn(const Sales_data *trans, Sales_data accum)//accum
{
    Sales_data item1(*trans), item2(accum);//item1, item2
    return item1.isbn() != item2.isbn();
}
```   

#### 13.13 A good way to understand copy-control members and constructors is to define a simple class with these members in which each member prints its name:  

```cpp
struct X {
    X() {std::cout << "X()" << std::endl;}
    X(const X&) {std::cout << "X(const X&)" << std::endl;}
};
```

#### Add the copy-assignment operator and destructor to X and write a program using X objects in various ways: Pass them as nonreference and reference parameters; dynamically allocate them; put them in containers; and so forth. Study the output until you are certain you understand when and why each copy-control member is used. As you read the output, remember that the compiler can omit calls to the copy constructor.  

[ex13_13.cpp](./ex13_13.cpp)  

```cpp
int main(){
    X* x = new X();//X()
    X y(*x);//X(const X&)
    y = *x;//X operator= 
    X z = *x;//X(const X&)
    delete x; //~X()
    return 0; 
}//~X(), ~X() for y and z respectively.  
```  

```
➜  ch13 git:(master) ✗ g++ ex13_13.cpp
ex13_13.cpp: In member function ‘X& X::operator=(const X&)’:
ex13_13.cpp:9:61: warning: no return statement in function returning non-void [-Wreturn-type]
    9 |     X& operator=(const X&){ cout << "X operator= " << endl; }
      |                                                             ^
      |                                                             return *this;
➜  ch13 git:(master) ✗ ./a.out
X()
X(const X&)
X operator= 
X(const X&)
~X()
~X()
~X()
```  

#### 13.14 Assume that numbered is a class with a **default constructor** that **generates a unique serial number** for each object, which is stored in a data member named mysn. Assuming numbered uses the synthesized copy-control members and given the following function:   

```cpp
void f (numbered s) { cout << s.mysn << endl; }
```  
#### what output does the following code produce?
```cpp
numbered a, b = a, c = b;
f(a); f(b); f(c);
```    

> Three identical numbers.  

[ex13_14.cpp](./ex13_14.cpp)  

```
➜  ch13 git:(master) ✗ g++ 13_14.cpp
➜  ch13 git:(master) ✗ ./a.out
10
10
10
```

#### 13.15 Assume numbered has a copy constructor that generates a new serial number. Does that change the output of the calls in the previous exercise? If so, why? What output gets generated?  

> Yes, the output will be changed. cause we don't use the synthesized copy-control members rather than own defined.The output will be three different numbers.    

[ex13_15.cpp](./ex13_15.cpp)  

```
➜  ch13 git:(master) ✗ g++ ex13_15.cpp
➜  ch13 git:(master) ✗ ./a.out
11
12
13
```

#### 13.16 What if the parameter in f were const numbered&? Does that change the output? If so, why? What output gets generated?  

> Yes, the output will be changed. cause the function f doesn't have any copy operators. Thus, the output are the same when we pass each object to f.  

[ex13_16.cpp](./ex13_16.cpp)  

```
➜  ch13 git:(master) ✗ g++ ex13_16.cpp
➜  ch13 git:(master) ✗ ./a.out
10
11
12
``` 


#### 13.17 Write versions of numbered and f corresponding to the previous three exercises and check whether you correctly predicted the output.

> see [ex13_14.cpp](./ex13_14.cpp), [ex13_15.cpp](./ex13_15.cpp), and [ex13_16.cpp](./ex13_16.cpp)   


#### 13.18 Define an Employee class that contains an employee name and a unique employee identifier. Give the class a default constructor and a constructor that takes a string representing the employee’s name. Each constructor should generate a unique ID by incrementing a static data member.  

[ex13_18.cpp](./ex13_18.cpp)  

```
➜  ch13 git:(master) ✗ g++ ex13_18.cpp
➜  ch13 git:(master) ✗ ./a.out
0
1
2
3
4
5
6
7
8
9
```  

#### 13.19 Does your Employee class need to define its own versions of the copy-control members? If so, why? If not, why not? Implement whatever copy-control members you think Employee needs.  

> No, since there are not two identical people.  

#### 13.20 Explain what happens when we copy, assign, or destroy objects of our TextQuery and QueryResult classes from § 12.3 (p. 484).  

> The member (smart pointer and container(map)) will be copied.  

#### 13.21 Do you think the TextQuery and QueryResult classes need to define their own versions of the copy-control members? If so, why? If not, why not? Implement whichever copy-control operations you think these classes require.  

> As synthesized version meet all requirements for this case, no custom version control members need to define.   

#### 13.22 Assume that we want HasPtr to behave like a value. That is, each object should have its own copy of the string to which the objects point. We’ll show the definitions of the copy-control members in the next section. However, you already know everything you need to know to implement these members. Write the HasPtr copy constructor and copy-assignment operator before reading on.  

```cpp
#ifndef CP5_ex13_11_h
#define CP5_ex13_11_h

#include <string>

class HasPtr {
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr& hp)
    {
        auto new_p = new std::string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    ~HasPtr() { delete ps; }
private:
    std::string* ps;
    int i;
};

#endif
```

[ex13_22.h](./ex13_22.h)  

#### 13.23 Compare the copy-control members that you wrote for the solutions to the previous section’s exercises to the code presented here. Be sure you understand the differences, if any, between your code and ours.  

> Check 13.22.  

#### 13.24 What would happen if the version of HasPtr in this section didn’t define a destructor? What if HasPtr didn’t define the copy constructor?  

> If HasPtr didn't define a destructor, memory leak will happened. (Synthesized destructor) 

> If HasPtr didn't define the copy constructor, when assignment happened, just points copied, the string witch ps points haven't been copied. (Synthesized copy constructor)

#### 13.25 Assume we want to define a version of StrBlob that acts like a value. Also assume that we want to continue to use a shared_ptr so that our StrBlobPtr class can still use a weak_ptr to the vector. Your revised class will need a copy constructor and copy-assignment operator but will not need a destructor. Explain what the copy constructor and copy-assignment operators must do. Explain why the class does not need a destructor.  

> Copy constructor and copy-assignment operator should dynamically allocate memory for its own , rather than share the object with the right hand operand.  

> Synthesized destructor will meet our requirements.  

#### 13.26 Write your own version of the StrBlob class described in the previous exercise.  

```cpp
StrBlob(const StrBlob& rhs):data(make_shared<vector<string>>(*rhs.data)){}  
    
StrBlob& operator=(const StrBlob& rhs){
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}
```

[ex13_26.h](./ex13_26.h)  

#### 13.27 Define your own reference-counted version of HasPtr.  

[ex13_27.h](./ex13_27.h)  

#### 13.28 Given the following classes, implement a default constructor and the necessary copy-control members.

(a)

```cpp
class TreeNode {
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
```

(b)

```cpp
class BinStrTree {
private:
    TreeNode* root;    
};  
```  

[ex13_28.h](./ex13_28.h)  

#### 13.29 Explain why the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop.  

> swap(lhs.ps, rhs.ps); feed the version : swap(std::string*, std::string*) and swap(lhs.i, rhs.i); feed the version : swap(int, int). Both them can't call swap(HasPtr&, HasPtr&). Thus, the calls don't cause a recursion loop.  

#### 13.30 Write and test a swap function for your valuelike version of HasPtr. Give your swap a print statement that notes when it is executed.    

[ex13_30.h](./ex13_30.h)  

#### 13.31 Give your class a < operator and define a vector of HasPtrs. Give that vector some elements and then sort the vector. Note when swap is called.  

[ex13_31.h](./ex13_31.h)    

#### 13.32 Would the pointerlike version of HasPtr benefit from defining a swap function? If so, what is the benefit? If not, why not?

> Essentially, the specific avoiding memory allocation is the reason why it improve performance. As for the pointer-like version, no dynamic memory allocation anyway. Thus, a specific version for it will not improve the performance.  

#### 13.33 Why is the parameter to the save and remove members of Message a Folder&? Why didn’t we define that parameter as Folder? Or const Folder&?

> Because these operations must also update the given Folder. Updating a Folder is a job that the Folder class controls through its addMsg and remMsg members, which will add or remove a pointer to a given Message, respectively.  

#### 13.34 Write the Message class as described in this section.  

[ex13_34.h](./ex13_34.h)  
[ex13_34.cpp](./ex13_34.cpp)  
[ex13_34_test.cpp](./ex13_34_test.cpp)  

```
➜  ch13 git:(master) ✗ g++ ex13_34_test.cpp ex13_34.cpp
➜  ch13 git:(master) ✗ ./a.out
hello
hello 
welcome to cppprimer
hello welcome to cppprimer 
hello
hello welcome to cppprimer 
```  

#### 13.35 What would happen if Message used the synthesized versions of the copy-control members?  

> some existing Folders will be out of sync with the Message after assignment.

#### 13.36 Design and implement the corresponding Folder class. That class should hold a set that points to the Messages in that Folder.  

> see ex13.34.  

#### 13.37 Design and implement the corresponding Folder class. That class should hold a set that points to the Messages in that Folder.

> see ex13.34.    

#### 13.38 We did not use copy and swap to define the Message assignment operator. Why do you suppose this is so?

> The copy and swap is an elegant way when working with dynamically allocated memory. In the Message class ,nothing is allocated dynamically. Thus using this idiom makes no sense and will make it more complicated to implement due to the pointers that point back.  

#### 


