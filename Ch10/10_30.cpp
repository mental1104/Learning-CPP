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
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}

/*
0 20 30 40 50 1 2 1 4 5 10 20 322 4444 10000 232
2123
2123 33334 412 213 432 213
0 1 1 2 4 5 10 20 20 30 40 50 213 213 232 322 412 432 2123 2123 4444 10000 33334 
*/