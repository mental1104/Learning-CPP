#include<iostream>

using namespace::std;

class base{
public:    
    base(){ a = new int[10]; }
    ~base() { delete []a; }
protected: 
    int* a;
};

class derive : public base{
public:
    derive(): base() { b = new int[20];}
    ~derive() { delete []b; }
protected:
    int* b;
};

int main(){
    base* temp = new derive();
    delete temp;
    return 0;
}