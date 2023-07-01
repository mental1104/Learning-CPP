#include<iostream>
#include<string>
#include<vector>

using namespace::std;

int main()
{
    vector<char> vec{'b', 'l', 'u', 'e'};
    string str(vec.begin(), vec.end());

    cout << str << endl;

    return 0;
}