#include<iostream>
#include<vector>


using namespace::std;

inline int add(int a, int b){
    return a+b;
}

inline int sub(int a, int b){
    return a-b;
}

inline int mul(int a, int b){
    return a*b;
}

inline int divi(int a, int b){
    return a/b;
}

int main(){
    vector<decltype(add)*> vec;
    decltype(add) (*padd) = add;
    decltype(add) (*psub) = sub;
    decltype(add) (*pmul) = mul;
    decltype(add) (*pdivi) = divi;
    vec.push_back(padd);
    vec.push_back(psub);
    vec.push_back(pmul);
    vec.push_back(pdivi);

    int a =10, b =2;
    cout<<vec[0](a,b)<<endl;
    cout<<vec[1](a,b)<<endl;
    cout<<vec[2](a,b)<<endl;
    cout<<vec[3](a,b)<<endl;

    return 0;

}