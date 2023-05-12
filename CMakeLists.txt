cmake_minimum_required(VERSION 3.23)
project(sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(sudoku main.cpp grid.h grid.cpp newgames.h ioutil.h ioutil.cpp)
