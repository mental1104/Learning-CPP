#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace::std;

int main(){
    ifstream in("ex8_04.txt");
    vector<string> str;
    string temp;
    while(getline(in,temp))
        str.push_back(temp);
    
    for(auto s:str){
        istringstream sin(s);
        while(sin >> temp)
            cout << temp << endl;
    }
    
    return 0;

}