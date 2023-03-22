cmake_minimum_required(VERSION 3.2.0)
project(CPP CXX)

set(CMAKE_C_COMPILER "which gcc")
set(CMAKE_CXX_COMPILE_FEATURES "which g++")
set(CMAKE_CXX_STANDARD 17)
set(TOP_DIR ${CMAKE_CURRENT_LIST_DIR}/)
set(PRIMER ${CMAKE_CURRENT_LIST_DIR}/primer)

add_subdirectory(primer)