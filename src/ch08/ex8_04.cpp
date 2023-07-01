#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace::std;

int main(){
    ifstream i("ex8_04.txt");
    string str;
    vector<string> devil;
    while(getline(i,str)){
        devil.push_back(str);
    }

    for(auto s : devil)
        cout << s << endl;
    return 0;
}

