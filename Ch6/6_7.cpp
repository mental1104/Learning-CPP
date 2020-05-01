#include<iostream>

using namespace::std;

int re(){
    static int i = 0;
    return i++;
}

int main(){
    int j = 0;
    while(j<100){
        cout<< re() << endl;
        j++;
    }
    return 0;
}