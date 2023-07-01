#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace::std;

int main(){
    vector<string> vec = {"Vergil","Dante","Vergil","Dante","Vergil","Vergil"};
    cout << count(vec.cbegin(), vec.cend(), "Vergil") << endl;
    return 0;
}