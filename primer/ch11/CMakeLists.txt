include_directories(${PRIMER}/ch07)

add_executable(EX11_03 ex11_03.cpp)
add_executable(EX11_07 ex11_07.cpp)
add_executable(EX11_08 ex11_08.cpp)
add_executable(EX11_11 ex11_11.cpp)
add_executable(EX11_12 ex11_12.cpp)
add_executable(EX11_14 ex11_14.cpp)
add_executable(EX11_16 ex11_16.cpp)
add_executable(EX11_20 ex11_20.cpp)
add_executable(EX11_23 ex11_23.cpp)
add_executable(EX11_26 ex11_26.cpp)
add_executable(EX11_31 ex11_31.cpp)
add_executable(EX11_32 ex11_32.cpp)
file(COPY ${PROJECT_SOURCE_DIR}/primer/ch11/word_transformation_bad.txt
     DESTINATION ${PROJECT_BINARY_DIR}/primer/ch11/)
file(COPY ${PROJECT_SOURCE_DIR}/primer/ch11/word_transformation.txt
     DESTINATION ${PROJECT_BINARY_DIR}/primer/ch11/)
file(COPY ${PROJECT_SOURCE_DIR}/primer/ch11/given_to_transform.txt
     DESTINATION ${PROJECT_BINARY_DIR}/primer/ch11/)
add_executable(EX11_33 ex11_33.cpp)
add_executable(EX11_38 ex11_38.cpp)