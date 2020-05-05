#include<iostream>
#include"StrBlob.h"


int main()
{
    const StrBlob csb{"hello", "world", "espeon"};
    StrBlob sb{"hello", "world", "wow"};

    std::cout << csb.front() << " " << csb.back() << std::endl;
    sb.back() = "you";
    std::cout << sb.front() << " " << sb.back() << std::endl;
}