#include<iostream>
#include<vector>
#include<string>

using namespace::std;

int main(){
    vector<string> vec;
    vec.push_back("You");
    vec.push_back("get");
    vec.push_back("soft");
    //*iter++;
    vector<string>::iterator iter = vec.begin();
    cout << *iter++ << " ";
    cout << *iter++ << " ";
    cout << *iter << " ";
    cout << endl;
    
    return 0;
}