#include<iostream>
#include<numeric>
#include<vector>
using namespace::std;

int main(){
    vector<double> vec = {1.0,2.0,3.0,4.0,5.5};
    cout << accumulate(vec.cbegin(),vec.cend(), 0) << endl;
    return 0;
}