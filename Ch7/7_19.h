#include<string>

class Person{
public:
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
private:   
    std::string name;
    std::string address;
}

