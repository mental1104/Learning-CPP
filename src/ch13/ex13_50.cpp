#include "ex13_49_String.h"
#include <vector>
#include <iostream>

// Test reference to http://coolshell.cn/articles/10478.html

void foo(String x)//copy-construcor
{
    std::cout << x.c_str() << std::endl;
}

void bar(const String& x)
{
    std::cout << x.c_str() << std::endl;
}

String baz()
{
    String ret("world");
    return ret;//avoid here
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0);//copy-construcor
    String s3 = s1;//copy-construcor
    String s4(text);
    s2 = s1;//copy-assignment

    foo(s1);//copy-construcor, hello
    bar(s1);//hello
    foo("temporary");//temporary
    bar("temporary");//temporary
    String s5 = baz();//avoid copy
    s5 = baz();//move assignment  

    std::vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);//copy-construcor
    svec.push_back(s1);//copy-construcor
    svec.push_back(s2);//copy-construcor
    svec.push_back(s3);//copy-construcor
    svec.push_back(s4);//copy-construcor
    svec.push_back(s5);//copy-construcor
    svec.push_back(baz());//move-construcor
    svec.push_back("good job");//move-constructor

    for (const auto& s : svec) {
        std::cout << s.c_str() << std::endl;
    }
}