#include<iostream>
using namespace::std;

void exch(int& i, int& j){
    int temp = i;
    i = j;
    j = temp;
}

int main(){
    int a = 50, b =100;
    exch(a, b);
    cout << a << " " << b << endl;
    return 0;
}