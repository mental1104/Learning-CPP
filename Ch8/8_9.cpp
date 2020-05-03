#include<iostream>
#include<sstream>

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
    istringstream in("come here.");
    func(in);
    return 0;
}