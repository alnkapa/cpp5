cmake_minimum_required(VERSION 3.25.1)

project(Editor VERSION 0.0.1)

add_executable(editor main.cpp)

target_include_directories(
    editor
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)


set_target_properties(editor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

