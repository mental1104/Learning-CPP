#include<iostream>

int main(){
    int a = 100;
    int z = 500;
    int b = 10000;
    int *c = &a;
    (*c)++;
    std::cout<< *c <<std::endl;//this will be 101.
    c =&b;
    std::cout<< *c <<std::endl;//this will be 10000.
    return 0;
}