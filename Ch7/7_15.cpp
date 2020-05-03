#include<string>

class Person{

    Person() = default;
    Person(const string& s):name(s){}
    Person(const string& n, const string & a):name(s),address(a){}
    
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    
    std::string name;
    std::string address;
}