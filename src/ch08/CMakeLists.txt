include_directories(${PRIMER}/ch07)

add_executable(EX8_01 ex8_01.cpp)
add_executable(EX8_04 ex8_04.cpp)
file(COPY ${PROJECT_SOURCE_DIR}/primer/ch08/ex8_04.txt 
     DESTINATION ${PROJECT_BINARY_DIR}/primer/ch08/)
add_executable(EX8_05 ex8_05.cpp)
add_executable(EX8_06 ex8_06.cpp ${PROJECT_SOURCE_DIR}/primer/ch07/ex7_26_sales_data.cpp)
file(COPY ${PROJECT_SOURCE_DIR}/primer/ch01/book_sales
     DESTINATION ${PROJECT_BINARY_DIR}/primer/ch08/)
add_executable(EX8_07 ex8_07.cpp ${PROJECT_SOURCE_DIR}/primer/ch07/ex7_26_sales_data.cpp)
add_executable(EX8_08 ex8_08.cpp ${PROJECT_SOURCE_DIR}/primer/ch07/ex7_26_sales_data.cpp)
add_executable(EX8_09 ex8_09.cpp)
add_executable(EX8_10 ex8_10.cpp)
add_executable(EX8_11 ex8_11.cpp)
add_executable(EX8_13 ex8_13.cpp)
file(COPY ${PROJECT_SOURCE_DIR}/primer/ch08/phonenumbers.txt
     DESTINATION ${PROJECT_BINARY_DIR}/primer/ch08/)