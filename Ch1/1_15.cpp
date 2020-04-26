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

/*******************************************************
 * ubuntu@VM-0-5-ubuntu:~/Project/Cpp-Primer/Ch1$ ./a.out
 * 50
 * 50
 * 12
 * 12
 * ^Z
 * [1]+  Stopped                 ./a.out
 * ubuntu@VM-0-5-ubuntu:~/Project/Cpp-Primer/Ch1$ ./a.out
 * 10
 * 10
 * ubuntu@VM-0-5-ubuntu:~/Project/Cpp-Primer/Ch1$
 */
  