#include<iostream>
using namespace::std;

int big(int a, const int* const p){
    return (a > *p) ? a : *p;
}

int main(){
    int i = 100;
    int j = 101;
    int const* p = &j;
    cout << big(i, p) <<endl;
}