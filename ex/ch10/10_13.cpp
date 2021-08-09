#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace::std;

bool fuc(const string& s){
    return s.size()>=5;
}

int main(){
    vector<string> vec{"vergil","nero","dante","sparda","lady","trish","v"};
    auto iter = partition(vec.begin(),vec.end(),fuc);
    auto curr = vec.begin();
    while(curr!=iter){
        cout << *curr << " ";
        ++curr;
    }
    cout << endl;
}