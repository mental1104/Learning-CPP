#include<iostream>
using namespace::std;

int para(int n){
    int num = 5;
    static int m = 0;
    if(n==6)
        num++;//you will easily find that when it's equal to 6 and num will be
        //6 , after that it come back to 5.
    m++;
    cout << " ";
    cout << "Times: " << m << " ";
    return num; 
}

int main(){

    int i = 1;
    while(1){
        cout << para(i) <<endl;
        if(i==10)
            break;
        i++;
    }
    return 0;
}