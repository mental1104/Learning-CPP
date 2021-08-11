#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

class BoundTest {
public:
    BoundTest(std::size_t l = 0, std::size_t u = 0) : lower(l), upper(u) {}
    bool operator()(const std::string& s)
    {
        return lower <= s.length() && s.length() <= upper;
    }

private:
    std::size_t lower;
    std::size_t upper;
};

int main()
{
    std::ifstream fin("../ch13/storyDataFile.txt");

    std::size_t quantity9 = 0, quantity10 = 0;
    BoundTest test9(1, 9);
    BoundTest test10(1, 10);

    for (std::string word; fin >> word;) {
        if (test9(word)) ++quantity9;
        if (test10(word)) ++quantity10;
    }

    std::cout << quantity9 << ", " << quantity10 << std::endl;
}
