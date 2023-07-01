#include<memory>
#include<iostream>
#include<vector>

using namespace::std;

shared_ptr<vector<int>> allocate(){
    return make_shared<vector<int>>();
}


void fn_read(shared_ptr<vector<int>> vec){
    int i;
    while(cin >> i)
        vec->push_back(i);
}

void print(shared_ptr<vector<int>> vec){
    for (const int& e : *vec) cout << e << " ";
    cout << "\n";
}

int main(){
    shared_ptr<vector<int>> ptr = allocate();
    fn_read(ptr);
    print(ptr);
    return 0;
}