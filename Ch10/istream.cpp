#include<iostream>
#include<numeric>
#include<iterator>

using namespace::std;

int main(){
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0) << endl;
    return 0;
}

/*
    Ctrl + D is needed.
    ubuntu@VM-0-5-ubuntu:~/Project/Cpp-Primer/Ch10$ ./a.out
    10 20 30 40 50 60 70 80 90 100
    550
*/