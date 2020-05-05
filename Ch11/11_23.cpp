#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace::std;

int main(){
    multimap<string, string> family;
    for(string child, last;cin>>last>>child;family.emplace(last,child));
    for(auto i:family)
        cout << i.second << " " << i.first << endl;
    return 0;
}