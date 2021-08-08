#include<iostream>
using namespace::std;

void exch(int* i, int* j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int main(){
    int a = 50, b =100;
    int* pa = &a;
    int* pb = &b;
    exch(pa,pb);
    cout << a << " " << b << endl;
    return 0;
}