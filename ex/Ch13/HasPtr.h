#ifndef CP5_ex13_05_h
#define CP5_ex13_05_h

#include <string>
using std::string;


class HasPtr {
public:

    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0)
    {
    }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr& rhs){
        string temp = new string(*rhs.ps);
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

    HasPtr& operator<(const HasPtr& lhs, const HasPtr& rhs){
        return *lhs.ps < *rhs.ps;
    }

    void show() { std::cout << *ps << std::endl; }

private:
    std::string* ps;
    int i;
    vector<HasPtr> vec;
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

#endif