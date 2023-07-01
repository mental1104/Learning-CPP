#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace::std;

void elimDups(vector<string>& vec){
    sort(vec.begin(),vec.end());
    auto end_unique = unique(vec.begin(),vec.end());
    vec.erase(end_unique, vec.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(){
    vector<string> vec = {"so","by", "You shall die", " My power shall be absolute", "so","by","fa","fa","fa","he","oh"};
    elimDups(vec);
    stable_sort(vec.begin(),vec.end(),isShorter);
    for(const auto &s: vec)
        cout << s << " ";
    cout << endl;
    return 0;
}