#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec;
    int i = 0;
    int num;
    while(cin>>num && i!=10){
        vec.push_back(num);
        ++i;
    }

    for(auto i = vec.begin(); i!=vec.end(); i++){
        *i<<=1;
        cout<< *i << " ";
    }
    cout<<endl;
    return 0;
}