cmake_minimum_required(VERSION 3.25.1)

project(MyAllocator VERSION 0.0.1)

add_executable(my_allocator main.cpp)

target_include_directories(
    my_allocator
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(my_allocator PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

