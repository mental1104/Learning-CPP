#include<iostream>
#include<vector>

using namespace::std;

vector<int>* allocate(){
    return new vector<int>();
}


void fn_read(vector<int>* vec){
    int i;
    while(cin >> i)
        vec->push_back(i);
}

void print(vector<int>* vec){
    for (const int& e : *vec) cout << e << " ";
    cout << "\n";
}

int main(){
    vector<int>* iter = allocate();
    fn_read(iter);
    print(iter);
    delete iter;
    iter = nullptr;
    return 0;
}