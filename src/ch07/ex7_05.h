#ifndef CP5_ex7_05_h
#define CP5_ex7_05_h

#include<string>

class Person{
public:
    const std::string& getName() const { return name; }
    const std::string& getAddress() const { return address; }
private:
    std::string name;
    std::string address;
};

#endif