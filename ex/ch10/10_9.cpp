#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace::std;

void elimDups(vector<string>& vec){
    sort(vec.begin(),vec.end());
    auto end_unique = unique(vec.begin(),vec.end());
    vec.erase(end_unique, vec.end());
}

int main(){
    vector<string> v = {"vergil","dante","nero","nico","vergil","dante","sparda"};
    elimDups(v);
    for(auto i:v)
        cout << i << " ";
    cout << endl;
    return 0;
}