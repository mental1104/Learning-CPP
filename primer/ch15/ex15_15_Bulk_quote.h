#ifndef CP5_EX15_15_BULK_QUOTE_H_
#define CP5_EX15_15_BULK_QUOTE_H_

#include "ex15_15_Disc_quote.h"
#include <string>

inline namespace EX15 {

    using std::string;

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(string const& book, double price, size_t qty, double disc) : Disc_quote(book, price, qty, disc) { }
    virtual double net_price(std::size_t cnt) const override {
        if (cnt >= quantity) return cnt * (1 - discount) * price;
        else return cnt * price;
    }
};

}

#endif // CP5_EX15_15_BULK_QUOTE_H_
