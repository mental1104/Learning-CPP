#include<iostream>
#include<string>

using namespace::std;

string& func(string& s, const string& a, const string& b){
    s.insert(0,a);
    s.insert(s.size(),b);
    return s;
}

int main(){
    string s("rocket");
    cout << func(s,"Team "," will never fall.") << endl;
    return 0;
}