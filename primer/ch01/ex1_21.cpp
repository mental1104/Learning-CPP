#include<iostream>
#include"Sales_item.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(){
    Sales_item A, B;
    cin >> A >> B;
    if(A.isbn() == B.isbn())
        cout << A + B << endl;
    else
        cerr << "Different ISBN." << endl;
    return 0;
}