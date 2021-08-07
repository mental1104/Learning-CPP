#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;

int main()
{
    // use string.
    string s1("Blue");
    string s2("Espeon");

    if (s1 == s2)
        cout << "same string." << endl;
    else if (s1 > s2)
        cout << "Blue > Espeon" << endl;
    else
        cout << "Blue < Espeon" << endl;

    cout << "=========" << endl;
    // use C-Style character strings.
    const char* cs1 = "Blue";
    const char* cs2 = "Espeon";

    auto result = strcmp(cs1, cs2);
    if (result == 0)
        cout << "same string." << endl;
    else if (result < 0)
        cout << "Blue < Espeon" << endl;
    else
        cout << "Blue > Espeon" << endl;

    return 0;
}