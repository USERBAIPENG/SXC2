#[[这是一个CMakeLists.txt文件
块注释用法]]
cmake_minimum_required(VERSION 3.10)

project (learn_cmake)
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

add_executable(myhello2 myhello.cpp) 