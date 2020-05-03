#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> a(10,5);
    vector<int> b(1,10);
    cout << (a < b) << endl;
    return 0;
}