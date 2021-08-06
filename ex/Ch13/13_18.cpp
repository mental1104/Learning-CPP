#include"ex13_18.h"
#include<iostream>

using namespace::std;

int Employee::s_increment = 0;

Employee::Employee(){
    id_ = s_increment++;
}

Employee::Employee(const string& rhs){
    id_ = s_increment++;
    name_ = name;
}