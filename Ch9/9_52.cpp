#include<iostream>
#include<string>
#include<stack>

using namespace::std;

int main(){
    auto& s = "Very (((((awesome))))) ((birthday) party).";
    auto rep = '-';
    int seen = 0;

    stack<char> sta;

    for(auto i:s){
        sta.push(i);
        if(i == '(') ++seen;
        if(seen && i == ')'){
            while(sta.top()!='(') sta.pop();
            sta.pop();
            sta.push(rep);
            --seen;
        }
    }

    string output;
    for(;!sta.empty();sta.pop()) output.insert(output.begin(),sta.top());
    cout << output << endl;
}