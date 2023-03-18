#ifndef CP5_ex7_48_h
#define CP5_ex7_48_h  

#include "ex7_41_sales_data.h"
#include <string>
using std::string;

int main(){
    string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);
    Sales_data item2("9-999-99999-9");
    return 0;
}
#endif