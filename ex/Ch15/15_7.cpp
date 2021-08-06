#include<cstddef>
#include<string>
#include<iostream>

using namespace::std;

class Limit{
    friend void output(std::ostream&, const Limit&);
public:
    Limit() = default;
    Limit(const string& i, double s, size_t n, size_t b, double d):
                    isbn(i),single(s),num(n),bound(b),discount(d) {}
    const string& get_isbn() const { return isbn; }
    
private:
    std::string isbn;
    double single;
    size_t num;
    size_t bound;
    double discount;
};

void output(std::ostream& os, const Limit& rhs)
{   
    double sum;
    if(rhs.num > rhs.bound){
        size_t temp = rhs.num - rhs.bound;
        sum = temp * rhs.single + rhs.bound * rhs.single * (1 - rhs.discount);
    }else
        sum = rhs.num * rhs.single;
    os <<  rhs.isbn << " # sold " << sum << "." << std::endl;
}

int main(){
    Limit ins("C++ Primer", 100, 50, 10, 0.3);
    output(std::cout, ins);
    return 0;
}