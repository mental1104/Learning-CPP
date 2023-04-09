#include <string>
#include <vector>
#include <iostream>

#include "filter.h"
using namespace::std;


int main(){
    Product apple{"Apple", Color::Green, Size::Small };
    Product tree{"Tree", Color::Green, Size::Large };
    Product house{"House", Color::Blue, Size::Large };

    vector<Product*> all {&apple, &tree, &house};

    BetterFilter bf;
    {
        
        ColorSpecification green(Color::Green);

        auto green_things = bf.filter(all, green);
        for(auto& x : green_things)
            cout << x->name << " is green" << endl;
    }
    
    cout << "--------------------------------" << endl;

    {
        SizeSpecification large(Size::Large);
        ColorSpecification green(Color::Green);
        AndSpecification<Product> green_and_large{large, green};
        auto big_green_things = bf.filter(all, green_and_large);
        for(auto& x : big_green_things){
            cout << x->name << " is large and green" << endl;
        }
    }
    

    return 0;
}