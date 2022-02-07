#include<iostream>
#include<cstring>

class String{
public:
    String(const char* rhs){
        data = new char[50];
        const char* temp = rhs;
        char* cur = data;
        while(*temp!='\0'){
            *cur = *temp;
            temp++;
            cur++;            
        }
        *cur = '\0';
    }
    const char& operator[](int r) const{
        return data[r];
    }

    char& operator[](int r){
        return const_cast<char&>(static_cast<const String&>(*this)[r]);
    }
private:
    char* data;
};

int main(){
    const String cs("const C-Style String");
    String s("C-Style String");
    printf("%c\n", cs[0]);
    printf("%c\n", s[0]);
    s[0] = 'J';
    printf("%c\n", s[0]);
}