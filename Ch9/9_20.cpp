#include<iostream>
#include<list>
#include<deque>

using namespace::std;

int main(){
    list<int> li = {1,2,3,4,5,6,7,8,9,10};
    deque<int> odd;
    deque<int> even;
    auto iter = li.begin();
    while(iter!=li.end()){
        if(*iter%2 ==0)
            even.push_back(*iter);
        else
            odd.push_back(*iter);
        iter++;
    }
    for(auto i:odd)
        cout<< i << " ";
    cout<<endl;

    for(auto i:even)
        cout<< i << " ";
    cout<<endl;

    return 0;
}
