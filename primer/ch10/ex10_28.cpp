#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace::std;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    vector<int> v1,v2;
    deque<int> d;
    copy(vec.begin(),vec.end(),inserter(v1,v1.begin()));
    copy(vec.begin(),vec.end(),back_inserter(v2));
    copy(vec.begin(),vec.end(),front_inserter(d));

    cout << "inserter v1: ";

    for(auto i : v1)
        cout << i << " ";
    cout << endl;

    cout << "back_inserter v2: ";

    for(auto i : v2)
        cout << i << " ";
    cout << endl;

    cout << "front_inserter d: ";

    for(auto i : d)
        cout << i << " ";
    cout << endl;

    return 0;
}

/* output

inserter v1: 1 2 3 4 5 6 7 8 9 
back_inserter v2: 1 2 3 4 5 6 7 8 9 
front_inserter d: 9 8 7 6 5 4 3 2 1 

*/