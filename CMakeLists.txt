cmake_minimum_required(VERSION 3.25.1)

project(PrintIp VERSION 0.0.1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")

add_executable(print_ip main.cpp)


target_include_directories(
    print_ip
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)


set_target_properties(print_ip PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

