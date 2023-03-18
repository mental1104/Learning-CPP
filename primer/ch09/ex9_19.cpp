#include<iostream>
#include<list>
#include<string>

using namespace::std;

int main(){
    string temp;
    list<string> que;
    while(cin>>temp)
        que.push_back(temp);

    for(auto i: que)
        cout << i << " ";
        
    cout << endl;
    return 0;
}