cmake_minimum_required(VERSION 3.25.1)

project(ipFilter VERSION 0.0.1)

add_executable(ip_filter main.cpp)

target_include_directories(
    ip_filter
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
set_target_properties(test_version PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
