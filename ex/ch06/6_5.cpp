#include<iostream>
using namespace::std;

int abs(int a){
    if(a<0)
        a=~a+1;
    return a;
}

int main(){
    int b;
    while(cin>>b)
        cout<< abs(b) << endl;
    
    return 0;
}