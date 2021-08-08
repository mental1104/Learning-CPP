#include<vector>
#include<iostream>

//#define NDEBUG

using namespace::std;

void print(vector<int>& a, vector<int>::iterator iter){

    #ifndef NDEBUG
    cout << "vector size: " << a.size() << endl;
    #endif

    if(iter!=a.end()){
        cout<<*iter<<" ";
        print(a,++iter);
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vec.begin();
    print(vec,iter);
    cout << endl;
}