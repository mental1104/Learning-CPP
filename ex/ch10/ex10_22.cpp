#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>


using std::string;
using namespace std::placeholders;

bool lessThanOrEqualTo(const string& s, string::size_type sz)
{
    return s.size() <= sz;
}

int main()
{
    std::vector<string> authors{"Mooophy", "pezy", "Queequeg90", "shbling",
                                "evan617"};
    std::cout << count_if(authors.cbegin(), authors.cend(),
                          bind(lessThanOrEqualTo, _1, 6));
    std::cout << std::endl;
    return 0;
}