#include<iostream>
#include<vector>
#include<string>

using namespace::std;

int main(){
    string word;
    vector<string> sequence;
    while(cin>>word)
        sequence.push_back(word);

    for(auto &str:sequence)
        str[0]&=0x5F;//convenient way to captialize a character
    
    for(auto st:sequence)
        cout<< st<<" ";
    return 0;
}