#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9,100};
    ostream_iterator<int> os(cout, " ");
    copy(vec.crbegin(),vec.crend(), os);
    cout << endl;
    return 0;
}