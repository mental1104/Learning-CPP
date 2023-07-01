#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9,100};
    for(auto iter = vec.cend();iter!=vec.cbegin();)
        cout << *--iter << " ";
    cout << endl;
    return 0;
}