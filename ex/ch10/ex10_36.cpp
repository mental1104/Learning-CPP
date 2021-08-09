#include<iostream>
#include<algorithm>
#include<iterator>
#include<list>

using namespace::std;

int main(){
    list<int> vec{1,2,0,3,4,5,0,4,5,7};
    auto found = find(vec.crbegin(),vec.crend(),0);
    cout << *found << endl;
    return 0;
}