#include<iostream>
#include<string>
#include<fstream>

using namespace::std;

int main(){
    ofstream out("slash");
    out << "You 're going down." << endl;
    out.close();
    return 0;
}