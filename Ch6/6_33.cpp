 #include<vector>
 #include<iostream>

 using namespace::std;

 void print(vector<int>& a, vector<int>::iterator iter){
     if(iter!=a.end()){
        cout<<*iter<<" ";
        print(a,++iter);
     }
 }

 int main(){

    vector<int> s(10,5);
    auto it = s.begin();
    print(s,it);
    return 0;
 }