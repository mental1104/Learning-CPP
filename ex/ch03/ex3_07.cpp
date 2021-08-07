#include<iostream>
#include<string>

using namespace::std;

int main(){
    string temp;
    cin >> temp;
    for(char& c:temp)//it must be char&
        c = 'X';
    cout<<temp<<endl;
    return 0;
}