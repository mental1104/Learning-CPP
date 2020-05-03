#include<iostream>
using namespace::std;

int main(){
    size_t s = 4611686018427387904;
    int cnt = 0;
    while(s!=1){
        s>>=1;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}

//vector<int> 62 