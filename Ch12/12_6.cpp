#include<iostream>
#include<vector>

using namespace::std;

vector<int>* returnVector(){
    vector<int>* ptr_v = new vector<int>();
    return ptr_v;
}


void reade(vector<int>* vec){
    int i;
    while(cin >> i)
        vec->push_back(i);
}

void print(vector<int>* vec){
    for (const auto& e : *vec) cout << e << " ";
    cout << "\n";
}

int main(){
    auto iter = returnVector();
    reade(iter);
    print(iter);
    delete iter;
    return 0;
}