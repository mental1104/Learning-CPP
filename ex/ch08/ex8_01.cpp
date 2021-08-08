#include<iostream>
using namespace::std;

istream& func(istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main(){
    string one;
    func(cin)>>one;
    return 0;
}