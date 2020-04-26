#include<iostream>
#include"Sales_item.h"

int main(){
    Sales_item currFile, valFile;
    if(std::cin >> currFile){
        int cnt = 1;
        while(std::cin >> valFile){
            if(valFile.isbn()==currFile.isbn())
                ++cnt;
            else{
                std::cout << currFile << " occurs "<< cnt << " times."
                          << std::endl;
                currFile = valFile;
                cnt=1;
            }                
        }
        std::cout << currFile << " occurs "<< cnt << " times."
                  << std::endl; 
    }
    return 0;
}

/**************************************************************
 * 1_24 needs to use redirection to book_sales
 * just like this: ./a.out <book_sales>1_24.txt  
 **************************************************************/