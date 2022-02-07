#include<iostream>

class Rational {
public:
    Rational():val(0){}
    Rational(int rhs):val(rhs){}
    int val;
};

Rational operator*(const Rational& lhs, const Rational& rhs){
    return lhs.val * rhs.val;
}

int main(){
    Rational a = 5;
    Rational b = 10;
    Rational c = 15;
    printf("%d\n", (a*b) = c);
    return 0;
}