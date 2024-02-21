cmake_minimum_required(VERSION 3.27)
project(LestaTestTask)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_executable(LestaTestTask main.cpp)

find_package(GTest CONFIG REQUIRED)
target_link_libraries(LestaTestTask PUBLIC GTest::gtest)

