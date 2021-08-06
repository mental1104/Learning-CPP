#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using namespace::std;

int main(){
    istream_iterator<int> it(cin), eof;
    vector<int> vec;
    while(it!=eof)
        vec.push_back(*it++);
    sort(vec.begin(),vec.end());
    ostream_iterator<int> out(cout, " ");
    unique_copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}