#include<vector>

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


int main()
{
    C c;

    std::vector<NoDefault> vec(10);
    return 0;
}

//error: no matching function for call to ‘NoDefault::NoDefault()’