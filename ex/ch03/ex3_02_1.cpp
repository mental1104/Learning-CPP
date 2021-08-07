#include<iostream>
#include<string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(){
    string temp;
    while(getline(cin, temp))
        cout << temp << endl;    
    return 0;
}