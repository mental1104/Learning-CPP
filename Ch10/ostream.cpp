#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    ostream_iterator<int> out(cout, "-");
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}