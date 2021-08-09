#include<iostream>
#include<algorithm>
#include<iterator>
#include<fstream>
#include<vector>

using namespace::std;

int main(){
    ifstream ifs("num.txt");
    ofstream of("odd.txt"), ef("even.txt");
    istream_iterator<int> in(ifs), eof;
    ostream_iterator<int> odd(of, " "), even(ef, "\n");

    vector<int> vo, ve;
    while(in!=eof){
        if(*in&0x1)
            vo.push_back(*in);
        else
            ve.push_back(*in);
        in++;
    }
    copy(vo.begin(),vo.end(),odd);
    copy(ve.begin(),ve.end(),even);
    return 0;
}