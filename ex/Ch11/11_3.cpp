#include<iostream>
#include<map>
#include<string>

using namespace::std;

int main(){
    string str;
    map<string,size_t> word_count;
    while(cin >> str)
        ++word_count[str];
    for(const auto &i: word_count)
        cout << i.first << " occurs " << i.second << " times. " << endl;
    return 0;
}

/*
ubuntu@VM-0-5-ubuntu:~/Project/Cpp-Primer/Ch11$ ./a.out
return 
return
out
out
o
o
w
w
w
w
vergil
o occurs 2 times. 
out occurs 2 times. 
return occurs 2 times. 
vergil occurs 1 times. 
w occurs 4 times. 
*/