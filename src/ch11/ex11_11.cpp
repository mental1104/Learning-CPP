#include "ex7_26_sales_data.h"
#include <set>

auto less(Sales_data const& lhs, Sales_data const& rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    using Less = bool (*)(Sales_data const&, Sales_data const&);
    std::multiset<Sales_data, Less> bookstore(less);
    return 0;
}