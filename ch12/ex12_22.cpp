#include <fstream>
#include <iostream>
#include "ex12_22.h"

int main()
{
    std::ifstream ifs("./ex12_20.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str);) blob.push_back(str);
    for (ConstStrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend;
         pbeg.incr())
        std::cout << pbeg.deref() << std::endl;
}