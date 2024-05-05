cmake_minimum_required(VERSION 3.25.1)

project(ipFilter VERSION 0.0.1)

add_executable(ip_filter main.cpp my_set.cpp my_ip.cpp)

target_include_directories(
    ip_filter
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

add_executable(test_ip_filter test_ip_filter.cpp my_set.cpp my_ip.cpp)

set_target_properties(test_ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

find_package(GTest REQUIRED)

target_link_libraries(test_ip_filter GTest::gtest_main)

add_test(read test_ip_filter)
add_test(read1 test_ip_filter)

enable_testing()
