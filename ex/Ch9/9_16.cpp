#include<iostream>
#include<vector>
#include<list>

using namespace::std;

int main(){
    vector<int> a(10,5);
    list<int> b(1,10);
    cout << (a < b) << endl;//can 't pass.
    return 0;
}