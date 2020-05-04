#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    list<int> li;
    copy(vec.crbegin() + 3, vec.crend() - 3, inserter(li,li.begin()));
    ostream_iterator<int> os(cout, " ");
    copy(li.begin(),li.end(), os);
    cout << endl;
    return 0;
}