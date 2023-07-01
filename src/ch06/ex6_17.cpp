#include<iostream>
#include<cctype>

using namespace::std;

bool hasUpper(const string& s){
    bool flag = false;
    for(auto i:s)
        if(isupper(i)) flag = true;
    return flag;
}

void toLower(string& s){
    for(auto& i:s)
        i |= 0x20;
}

int main(){
    string str = "YOU ARE GOING DOWN.";
    cout<< hasUpper(str) << endl;
    toLower(str);
    cout << str <<endl;
    return 0;
}