#include<iostream>
#include<string>

using namespace::std;

int main(){
    string temp;
    string total;
    while(cin >> temp)
        total = total + " " + temp;
    cout << total <<endl;
    return 0;
}