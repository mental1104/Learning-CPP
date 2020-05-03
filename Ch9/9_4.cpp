#include<iostream>
#include<vector>

using namespace::std;

bool search(vector<int>::iterator b, vector<int>::iterator e, int i){
    while(b!=e){
        if(*b==i)
            return true;
        b++;
    }
    return false;
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    auto begin = a.begin();
    auto end   = a.end();
    cout << search(begin,end,5)<<endl;
    return 0;
}