#include <string>
#include <iostream>
using namespace::std;

std::string global_str; //empty string
int global_int; //0

int main()
{
    int local_int; //undefined
    std::string local_str; //empty string
    std::cout << "global_str:\t" << global_str << std::endl;
    std::cout << "global_int:\t" << global_int << std::endl;
    std::cout << "local_str:\t" << local_str << std::endl;
    std::cout << "local_int:\t" << local_int << std::endl;
    return 0;
}