cmake_minimum_required(VERSION 3.20)
project(alphastream)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(alphastream
    src/main.cpp
    src/order_book.cpp
)