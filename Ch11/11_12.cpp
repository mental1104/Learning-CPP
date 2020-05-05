#include<iostream>
#include<string>
#include<utility>
#include<vector>

using namespace::std;

int main(){
    vector<pair<string,int>> vec;
    string str;
    int i;  
    while(cin >> str >> i){
        vec.push_back(make_pair(str,i));
    }

    for(auto i: vec)
        cout << i.first << " : " << i.second << endl;
    return 0;
    
}