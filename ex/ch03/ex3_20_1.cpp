#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec;
    int num;
    while(cin>>num)
        vec.push_back(num);
    for(decltype(vec.size()) i = 0; i!=vec.size()-1;++i)
        cout << vec[i] + vec[i+1] << " ";
    cout << endl;
    return 0;
}