#include <iostream>
#include <string>
#include <memory>

using std::string; using std::unique_ptr;

int main()
{
    unique_ptr<string> p1(new string("espeon"));
    //unique_ptr<string> p2(p1); // copy
    //   414 |       unique_ptr(const unique_ptr&) = delete;
    //       |       ^~~~~~~~~~
    //unique_ptr<string> p3 = p1; // assign
     //   414 |       unique_ptr(const unique_ptr&) = delete;
    //       |       ^~~~~~~~~~
    std::cout << *p1 << std::endl;
    p1.reset(nullptr);
}