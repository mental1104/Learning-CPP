#include<iostream>
#include<fstream>
#include<string>

using namespace::std;

int main(int argc, char **argv){
    if(argc!=2){
        return 0;
    }
    
    ofstream out(argv[1],ofstream::app);
    out << "Congratulations!" << endl;
    return 0;
}