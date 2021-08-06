#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace::std;

int main(){
    string str;
    map<string,size_t> word_count;
    set<string> s = {"a","b","c","w"};
    
    while(cin >> str)
        if(s.find(str)==s.end())
            ++word_count[str];

    for(const auto &i: word_count)
        cout << i.first << " occurs " << i.second << " times. " << endl;
    return 0;
}
