#include<bitset>
#include<iostream>

using namespace::std;

int main(){
    bitset<32> bit;
    bit.set(1);
    bit.set(2);
    bit.set(3);
    bit.set(5);
    bit.set(8);
    bit.set(13);
    bit.set(21);

    bitset<32> bit_k(bit);
    cout << bit_k << endl;
    return 0;
}