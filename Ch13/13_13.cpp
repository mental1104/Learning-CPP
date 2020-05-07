#include<iostream>

using namespace::std;

struct X{
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    ~X() { cout << "~X()" << endl;}
};

int main(){
    X* x = new X();
    X y(*x);
    delete x;
    return 0;
    
}

/*
    X()
    X(const X&)
    ~X()
    ~X()
*/