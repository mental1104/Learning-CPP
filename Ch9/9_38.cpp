#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> vec;
    vec.reserve(10);
    cout << "size: " << vec.size() << "  capacity: " << vec.capacity() << endl; 
    int i = 0;
    while(cin >> i){
        vec.push_back(i);
        cout << "size: " << vec.size() << "  capacity: " << vec.capacity() << endl; 
    }
    return 0;
}