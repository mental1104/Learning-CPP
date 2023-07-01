#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>

using namespace::std;

int main(){
    string s;
    cin >> s;
    char* c = new char[s.size()+1]();
    strcpy(c,s.c_str());

    printf("%s\n",c);
    delete[] c;
    return 0;
}