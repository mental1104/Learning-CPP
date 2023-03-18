#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec;
    int num;
    while(cin>>num)
        vec.push_back(num);

    for(auto i = vec.cbegin();i!=vec.cend()-1;++i)
        cout << *i + *(i+1) << " ";  
    cout << endl;
    return 0;
}