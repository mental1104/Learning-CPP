#ifndef CP5_ex13_30_h
#define CP5_ex13_30_h

#include <string>
using std::string;
#include <iostream>


class HasPtr {
public:
    friend void swap(HasPtr& lhs, HasPtr& rhs);
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr& rhs){
        string* temp = new string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    } 
    ~HasPtr() { delete ps; }

    HasPtr& operator=(const HasPtr& rhs){
        string* str = new string(*rhs.ps);
        delete ps;//delete the original space;

        ps = str;
        i = rhs.i;
        return *this;
    }
private:
    std::string* ps;
    int i;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

#endif