#include<iostream>
#include<string>

using namespace::std;

void Replace(string& s, const string& a, const string& b){
    for(decltype(s.size()) i = 0; i!=s.size();++i){
        if((s.substr(i,a.size())==a)){
            s.replace(i,a.size(),b);
            i += b.size()-1;
        }
    }
}
int main(){
    string s = "Wait a second did ya go out tonight? ya have to fill me in.";
    Replace(s,"ya","you");
    cout << s << endl;
    return 0;
}