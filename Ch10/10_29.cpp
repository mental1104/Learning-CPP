#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
#include<algorithm>

using namespace::std;

int main(){
    ifstream ifs("ex8_4.txt");
    istream_iterator<string> is(ifs), eof;
    vector<string> vec;

    while(is!=eof)
        vec.push_back(*is++);

    ostream_iterator<string> out(cout, " ");
    copy(vec.begin(), vec.end(), out);
    cout << endl;
    return 0;
}