#include<iostream>
#include"16_2.h"
#include"/home/ubuntu/Project/Cpp-Primer/Ch2/2_42.h"

using namespace::std;

int main()
{
    Sales_data a("C Primer Plus"), b("C++ Primer");
    cout << compare(a,b) << endl;
    return 0;
    /*************************************************************
     usr/include/c++/7/system_error:282:3: note:   no known conversion for argument 1 from ‘const Sales_data’ to ‘const std::error_condition&’
     In file included from 16_3.cpp:2:0:
     16_2.h:9:9: error: no match for ‘operator<’ (operand types are ‘const Sales_data’ and ‘const Sales_data’)
     if(b<a) return 1;
    **********************************************************/
}