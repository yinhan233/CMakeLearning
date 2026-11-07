cmake_minimum_required(VERSION 3.30)
project(ComplexCalculator VERSION 0.1 DESCRIPTION "demo" LANGUAGES CXX)
#添加可执行程序
add_executable(demo)
target_sources(demo
    PRIVATE
        main.cpp
)
# 添加库
add_library(complex)
target_sources(complex PRIVATE complex.cpp complex.h)
# 链接库
target_link_libraries(demo PRIVATE complex)