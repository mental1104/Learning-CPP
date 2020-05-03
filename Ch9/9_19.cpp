#include<iostream>
#include<list>
#include<string>

using namespace::std;

int main(){
    string temp;
    list<string> que;
    auto iter = que.begin();
    while(cin>>temp)
        iter = que.insert(iter, temp);

    while(iter!=que.end())
        cout<<*(iter++)<<" ";
        
    cout << endl;
    return 0;
}