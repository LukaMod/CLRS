cmake_minimum_required(VERSION 3.12)
project(CLRS)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(mytest main.cpp test/test.cpp)