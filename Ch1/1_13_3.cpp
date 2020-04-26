#include<iostream>

int main(){
    int small = 0, big = 0, sum = 0;
    std::cout << "Enter two different value to form a range. "
              << std::endl;
    std::cin >> small >> big;

    if(small > big){
        int temp = small;
        small = big;
        big = temp;
    }

    int backup = small;

    for(;small <= big;++small)
        sum += small;

    std::cout << "Sum of "
              << backup <<" and "<< big << " inclusive is "
              << sum << std::endl;
    return 0;
}