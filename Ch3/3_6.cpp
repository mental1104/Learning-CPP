#include<iostream>
#include<string>

using namespace::std;

int main(){
    string temp;
    cin>>temp;
    for(auto &c:temp)
        c = 'X';
    cout<<temp<<endl;
    return 0;
}