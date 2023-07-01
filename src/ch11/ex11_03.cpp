#include<iostream>
#include<map>
#include<string>

using namespace::std;

int main(){
    string str;
    map<string,size_t> word_count;
    while(cin >> str)
        ++word_count[str];
    for(const auto &i: word_count)
        cout << i.first << " occurs " << i.second << " times. " << endl;
    return 0;
}