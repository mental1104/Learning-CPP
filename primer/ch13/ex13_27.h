#ifndef CP5_ex13_27_h
#define CP5_ex13_27_h 

#include<string>
using std::string;

class HasPtr{ 
public:  
    HasPtr(const string& rhs = string()):ps(new string(rhs)), i(0), use(new size_t(1)){}
    HasPtr(const HasPtr& rhs):ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }  
    HasPtr& operator=(const HasPtr& rhs){
        ++*rhs.use;
        if(*--use == 0){
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    ~HasPtr(){
        if(*--use == 0){
            delete ps;
            delete use;
        }
    }

private: 
    string* ps;
    int i;
    size_t* use;
};

#endif