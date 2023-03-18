#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> a(10,5);
    vector<int> b(1,10);
    vector<int> c(1,10);
    cout << ((a == b)?"true":"false") << endl;
    cout << ((b == c)?"true":"false") << endl;
    return 0;
}