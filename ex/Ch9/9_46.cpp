#include<iostream>
#include<string>

using namespace::std;

string& func(const string &s, const string& a, const string& b){
    string temp(s);
    s.insert(0,a);
    s.insert(temp.size(),b);
    return temp;
}

int main(){
    string s("rocket");
    cout << func(s,"Team "," will never fall.") << endl;
    return 0;
}