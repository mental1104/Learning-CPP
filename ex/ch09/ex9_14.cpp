#include<iostream>
#include<vector>
#include<list>

using namespace::std;

int main(){
    list<const char*> li(10,"vergil");
    vector<string> vec;
    vec.assign(li.begin(),li.end());
    for(auto i:vec)
        cout<< i << " ";
    cout << endl;
    return 0;
}