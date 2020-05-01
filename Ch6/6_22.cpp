#include<iostream>
using namespace::std;

void swap(const int*& i,const int*& j){
    auto temp = i;
    i = j;
    j = temp;
}

int main(){
    const int a = 50;
    const int b = 40;
    const int* ptr1 = &a;
    const int* ptr2 = &b;
    swap(ptr1,ptr2);
    cout << *ptr1 << " " << *ptr2 << endl;
    return 0;
}