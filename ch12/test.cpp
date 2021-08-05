#include<iostream>
#include<memory>

using namespace::std;

void process(shared_ptr<int> sp){
    cout << sp.use_count() << endl;//1
    return;
}
int main(){
    int *p = new int(100);
    process(shared_ptr<int>(p));
    for(int i = 0; i < 100; i++){
        *p = 1000;
        p++;
    }
    return 0;
}