#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec;
    cout << vec.at(0) << endl;
    cout << vec[0] << endl;
    cout << vec.front() << endl;
    cout << *vec.begin() << endl;
    return 0;
}

//terminate called after throwing an instance of 'std::out_of_range'
// what():  vector::_M_range_check: __n (which is 0) >= this->size() (which is 0)