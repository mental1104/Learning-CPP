#include<iostream>
#include<stdexcept>

using namespace::std;

int main(){
    int i,j;
    
    while(cin >> i >> j){
        try {
            if(j == 0) throw runtime_error("divisor is zero.");
            cout<< i/j << endl;
            cout<<"Input two integer."<<endl;
        } catch(runtime_error err){
            cout << err.what();
            cout << "\nTry Again? Enter y or n:" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
            else
                cout << "Input two integers: ";
        }
    }
}