#include<iostream>
#include<vector>

using namespace::std;

vector<int>::iterator search(vector<int>::iterator b, vector<int>::iterator e, int i){
    while(b!=e){
        if(*b==i)
            return b;
        b++;
    }
    return end;
}


