#include<iostream>
#include<algorithm>
#include<vector>
#include<string>


using namespace::std;

int main(){
    vector<string> vec = {"vergil","nero","dante","sparda","trish","lady"};
    auto i = count_if(vec.begin(),vec.end(),[](const string& s){ return s.size()>= 6;});
    cout << i << endl;
    return 0;
}