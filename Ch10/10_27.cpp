#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>

using namespace::std;

int main(){
    vector<int> vec{1,1,3,3,5,5,7,7,9,9};
    list<int> li;
  
    unique_copy(vec.begin(),vec.end(),inserter(li,li.begin()));
    for(auto i: li)
        cout << i << " ";
    cout << endl;
    return 0;
}