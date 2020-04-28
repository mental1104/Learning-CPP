/*global_str: empty  
  global_int: 0  
  local_int: uninitialized, undefined value.  
  local_string: It depends on the class, in this situation it should be empty string.  */
  #include<iostream>
  
  int global_int;
  int main(){
      int local_int;
      std::cout<< global_int << local_int <<std::endl;//local_int is undefined but it turns out
      //to be 0 in this situation.
      return 0;
  }