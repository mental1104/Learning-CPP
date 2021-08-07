/*******************************************************
 * test EOF
 * unix Ctrl + D
 * Windows Ctrl + Z
 */

#include<iostream>

int main(){
    int a = 0;
    while(std::cin >> a)
        std::cout << a << std::endl;
    return 0;
}
