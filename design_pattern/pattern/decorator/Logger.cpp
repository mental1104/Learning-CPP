#include "Logger.h"

double add(double a, double b) {
    cout << a << "+" << b << "=" << (a + b) << endl;
    return a + b;
}

int main() {

    // {
    //     Logger([]() { cout << "Hello\n"; }, "HelloFunction")();   
    // }

    // {
    //     auto call = make_logger2([]() { cout << "Hello!" << endl; }, "HelloFunction");
    //     call();
    // }
        
    {
        auto logged_add = make_logger3(add, "Add");
        auto result = logged_add(2, 3);
        cout << result << endl;
    }
    return 0;
}