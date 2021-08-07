#ifndef CP5_ex7_15_h
#define CP5_ex7_15_h

#include<string>

class Person{

    Person() = default;
    Person(const std::string& s):name(s){}
    Person(const std::string& n, const std::string & a):name(n),address(a){}
    
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    
    std::string name;
    std::string address;
};

#endif
