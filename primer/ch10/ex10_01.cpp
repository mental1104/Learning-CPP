#include<iostream>
#include<algorithm>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec = {1,2,2,2,3,4,4,5,5,5,5,5,5,5,5,6,7,7,7,7};
    cout << count(vec.cbegin(), vec.cend(), 5) << endl;
    return 0;
}