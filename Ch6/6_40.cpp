#include<iostream>
#include<string>

using namespace::std;

string make_plural(const string& word, const string &ending = "s"){
    return word + ending;
}

int main(){
    cout << make_plural("success","es") << endl;
    cout << make_plural("failure") << endl;
    return 0;
}