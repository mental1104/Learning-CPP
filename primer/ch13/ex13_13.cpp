#include<iostream>

using namespace::std;

struct X{
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    ~X() { cout << "~X()" << endl;}
    X& operator=(const X&){ cout << "X operator= " << endl; return *this; } 
};

int main(){
    X* x = new X(); //X()
    X y(*x);        //X(const X&)
    y = *x;         //X operator= 
    X z = *x;       //X(const X&)
    delete x;       //~X()
    return 0; 
}                   //~X(), ~X() for y and z respectively.  