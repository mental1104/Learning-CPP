#include<iostream>
#include<forward_list>
#include<string>

using namespace::std;

void func(forward_list<string>& li,const string a,const string b){
    auto prev = li.before_begin();
    auto size = distance(li.begin(),li.end());
    for(auto curr = li.begin();curr !=li.end(); prev = curr++)
        if(*curr == a) li.insert_after(curr,b);
    
    if(size == distance(li.begin(), li.end())) li.insert_after(prev,b);

}
int main(){
    forward_list<string> f = {"Vergil","will","cry"};
    func(f,"will","not");
    for(auto i:f)
        cout << i << " ";
    cout << endl;
    return 0;
}