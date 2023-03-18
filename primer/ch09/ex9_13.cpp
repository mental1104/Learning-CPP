#include<vector>
#include<list>
#include<iostream>

using namespace::std;

int main(){
    list<int> li{1,2,3,4,5,6,7,8,9};
    vector<int> v{1,2,3,4,5};
    vector<double> vec_1(li.cbegin(), li.cend());
    vector<double> vec_2(v.cbegin(),v.cend());
    for(auto i: vec_1)
        cout << i << " ";
    cout << endl;

    for(auto i: vec_2)
        cout << i << " ";
    cout << endl;

    return 0;
}