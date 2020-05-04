#include<iostream>
#include<numeric>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec(10,5);
    cout << accumulate(vec.cbegin(),vec.cend(),0) << endl;
    return 0;
}