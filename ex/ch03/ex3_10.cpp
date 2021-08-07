#include<iostream>
#include<cctype>
using namespace::std;

int main(){
    string a("you,are,not");
    for(decltype(a.size()) i = 0; i!=a.size(); i++){
        if(ispunct(a[i]))
            continue;
        cout << a[i];
    }
    cout << endl;
    return 0;
}