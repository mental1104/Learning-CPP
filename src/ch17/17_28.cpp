#include<random>
#include<iostream>

using namespace::std;

unsigned return_random(){
    static default_random_engine e;
    static uniform_int_distribution<unsigned> u(0,100);
    return u(e);
}
int main(){

    for(size_t i = 0; i<100; ++i)
        cout << return_random() << " ";
    cout << endl;
    return 0;
}