#include "ex12_02.h"
#include <iostream>

int main()
{
    const StrBlob csb{ "hello", "world", "const-espeon" };
    StrBlob sb{ "hello", "world", "const-espeon" };

    std::cout << csb.front() << " " << csb.back() << std::endl;
    //csb.back() = "espeon";//This one will trigger compliation fault.
    sb.back() = "espeon";
    std::cout << sb.front() << " " << sb.back() << std::endl;
    return 0;
}