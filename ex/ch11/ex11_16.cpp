#include<iostream>
#include<map>
#include<string>
#include<utility>

using namespace::std;

int main(){
    map<int,string> m;
    m[25] = "dante";
    auto iter = m.begin();
    iter->second = "vergil";
    cout << iter->second << endl;
    cout << m[25] << endl;
    return 0;
}