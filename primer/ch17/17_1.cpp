#include<tuple>
#include<iostream>

using namespace::std;

int main()
{
    tuple<int,int,int> a{10,20,30};
    cout << get<0>(a) << " " << get<1>(a) << " " 
         << get<2>(a) << endl;
    return 0;
}