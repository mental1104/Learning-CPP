#include<string>

class Person{
public:
    Person() = default;
    Person(std::string n, std::string a):name(n),address(a){}
    explicit Person(std::string n):name(n){}

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
private:   
    std::string name;
    std::string address;
}

//explicit: (istream -> Person) -------> constructor: Person(istream&)

