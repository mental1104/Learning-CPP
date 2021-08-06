#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace::std;

int main(){
    map<string, vector<string>> fml;
    string lastName, child;

    while([&]()->bool{
        cout << "Please ENTER lastname." << endl;

        return cin >> lastName && lastName!="q";
        }()
    )

    {
        cout << "Please ENTER Child's Name." << endl;
        while(cin >> child)
            fml[lastName].push_back(child);
    }

    for(auto i : fml){
        cout << i.first << ":\n";

        for(auto c: i.second) cout << c << " ";
        
        cout << "\n";
    }

    return 0;
}