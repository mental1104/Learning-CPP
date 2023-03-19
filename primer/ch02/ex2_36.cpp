#include <iostream>

int main(){
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    \
    std::cout << "a:\t" << a << std::endl;
    std::cout << "b:\t" << b << std::endl;
    std::cout << "c:\t" << c << std::endl;
    std::cout << "d:\t" << d << std::endl;
    return 0;
}