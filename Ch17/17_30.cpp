#include<random>
#include<iostream>
#include<tuple>

using namespace::std;

tuple<unsigned, size_t, size_t> return_random(size_t i){
    static default_random_engine e(i);
    static uniform_int_distribution<unsigned> u(0,100);
    return make_tuple(u(e),e.min(),e.max());
}

int main(){

    for(size_t i = 0; i<100; ++i)
        cout << get<0>(return_random(100-i)) << " ";
    cout << endl;
    cout << get<1>(return_random(1)) << " " << get<2>(return_random(1)) << endl;
    return 0;
}