#ifndef CP5_ex2_40_h
#define CP5_ex2_40_h

#include <string>  

struct Sale_data {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
};

#endif