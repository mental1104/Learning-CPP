#include<iostream>

int main()
{
    int a = 0, sum = 0;
    std::cout << "Enter some values(Ctrl+D to cancel)."<<std::endl;
    while(std::cin >> a)
        sum += a;
    std::cout << "The sum of these numbers is " << sum << std::endl;
    return 0;
}