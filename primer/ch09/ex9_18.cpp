#include<iostream>
#include<deque>
#include<string>

using namespace::std;

int main(){
    string temp;
    deque<string> que;
    while(cin>>temp)
        que.push_back(temp);

    auto iter = que.cbegin();
    for(;iter!=que.cend();++iter)
        cout<<*iter<<" ";
    cout << endl;
    return 0;
}