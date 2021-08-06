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
    int i = 0;
    while(i<10){
        cout<< one << " ";
        i++;
    }
    return 0;
}