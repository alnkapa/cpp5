cmake_minimum_required(VERSION 3.25.1)

project(Editor VERSION 0.0.1)

add_subdirectory(UI)

add_executable(editor main.cpp)

target_include_directories(
    editor
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    UI
)
target_link_libraries(
    editor
    UI
)

set_target_properties(editor PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

set(CMAKE_BUILD_TYPE Debug)


