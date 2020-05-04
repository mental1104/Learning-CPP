#include<iostream>
#include<string>

using namespace::std;

void Replace(string& s, const string& a, const string& b){
    
    for(auto iter = s.begin();distance(iter,s.end())>=distance(a.begin(),a.end());){
        if(string(iter,iter+a.size()) == a){
            iter = s.erase(iter,iter+a.size());
            iter = s.insert(iter, b.begin(),b.end());
            advance(iter,b.size());
        }
        else
            ++iter;
    }
}
int main(){
    string a = "altho you have the power,  tho you still need to go thru thru thru it.";
    Replace(a,"tho","though");
    Replace(a,"thru","through");
    cout << a << endl;
    return 0;
}