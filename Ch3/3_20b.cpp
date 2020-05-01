#include<iostream>
#include<vector>

using namespace::std;

int main(){
    vector<int> ivec;
    int num;

    while(cin>>num)
        ivec.push_back(num);

    decltype(ivec.size()) size = ivec.size();
    if (size % 2 != 0)
        size = size / 2 + 1;
    else
        size /= 2;

    for (decltype(ivec.size()) i = 0; i != size; ++i)
        cout << ivec[i] + ivec[ivec.size() - i - 1] << " ";
    cout << endl;

    return 0;
}