#include<iostream>
#include<string>

using namespace::std;


int main(){
    string numbers{"0123456789"};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string s("ab2c3d7R4E6");

    cout << "numeric characters: ";
    for(decltype(s.size()) pos = 0; (pos=s.find_first_of(numbers, pos))!=string::npos;
                                    ++pos){
        cout << s[pos] << endl;
    }

    cout << "\nalphabetic characters: ";
    for(decltype(s.size()) pos = 0; (pos=s.find_first_of(alphabet, pos))!=string::npos;
                                    ++pos){
        cout << s[pos] << endl;
    }
    cout << endl;
    return 0;

}