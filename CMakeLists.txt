cmake_minimum_required(VERSION 3.25.1)

project(MyAllocator VERSION 0.0.1)

add_executable(my_allocator_03 main03.cpp)

target_include_directories(
    my_allocator_03
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(my_allocator_03 PROPERTIES
    CXX_STANDARD 98
    CXX_STANDARD_REQUIRED ON
)

