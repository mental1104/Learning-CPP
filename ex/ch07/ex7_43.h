#ifndef CP5_ex7_43_h
#define CP5_ex7_43_h

class NoDefault{
public:
    NoDefault(int a){}

};

class C{
public:
    C():X(0){}
private:
    NoDefault X;
};

#endif