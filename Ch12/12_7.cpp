#include<memory>
#include<iostream>
#include<vector>

using namespace::std;

shared_ptr<vector<int>> returnVector(){
    
    return make_shared<vector<int>>();
}


void reade(shared_ptr<vector<int>> vec){
    int i;
    while(cin >> i)
        vec->push_back(i);
}

void print(shared_ptr<vector<int>> vec){
    for (const auto& e : *vec) cout << e << " ";
    cout << "\n";
}

int main(){
    auto ptr = returnVector();
    reade(ptr);
    print(ptr);
    return 0;
}