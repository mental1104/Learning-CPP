#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string str("a simple string");
    // use while
    decltype(str.size()) i = 0;
    while (i < str.size()) {
        str[i] = 'X';
        ++i;
    }
    cout << str << endl;

    
}