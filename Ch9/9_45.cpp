#include<iostream>
#include<string>

using namespace::std;

string& func(string& s, const string& a, const string& b){
    auto iter = s.begin();
    s.insert(s.begin(),a.begin(),a.end());
    s.append(b);
    return s;
}

int main(){
    string s = "Vergil";
    cout << func(s,"Mr."," will never fall") << endl;
    return 0;
}