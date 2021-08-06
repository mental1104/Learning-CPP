#include"15_3(Quote).h"
#include"15_5(Bulk).h"

#include<iostream>
#include<string>
using namespace::std;

int main()
{   
    Quote bs("C Primer Plus", 40);
    Bulk_quote cpp("C++ Primer", 90, 10, 0.3);

    print_total(cout, bs, 50);
    print_total(cout, cpp, 100);
    return 0;
}