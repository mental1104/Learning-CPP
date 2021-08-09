#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void elimdups(std::vector<std::string>& vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies(std::vector<std::string>& vs, std::size_t sz)
{
    using std::string;

    elimdups(vs);

    //! sort by size, but maintain alphabetical order for same size.
    std::stable_sort(vs.begin(), vs.end(),
                     [](string const& lhs, string const& rhs) {
                         return lhs.size() < rhs.size();
                     });

    //! get an iterator to the first one whose size() is >= sz
    auto wc = stable_partition(vs.begin(), vs.end(),
                           [sz](string const& s) { return s.size() >= sz; });

    std::stable_sort(vs.begin(), wc,
                     [](string const& lhs, string const& rhs) {
                         return lhs.size() < rhs.size();
                     });
    //! print the biggies
    std::for_each(vs.begin(), wc, [](const string& s) { std::cout << s << " "; });
}

int main()
{
    //! ex10.18
    std::vector<std::string> v{"1234", "1234", "1234", "hi~",
                               "alan", "alan", "cp"};
    std::cout << "ex10.18: ";
    biggies(v, 3);
    std::cout << std::endl;

    return 0;
}