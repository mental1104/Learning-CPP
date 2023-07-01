#include<iostream>
#include<algorithm>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec(10,30);
    fill_n(vec.begin(),vec.size(),0);
    for(auto i:vec)
        cout << i << " ";
    cout << endl;
    return 0;
}