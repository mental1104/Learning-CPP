#include<iostream>
using namespace::std;

int fact(int n){
    int sum = 1;
    while(n){
        sum = sum*n;
        n--;
    }
    return sum;
}

int main(){
    int s;
    cin >> s;
    cout << fact(s) << endl;
    return 0; 
}