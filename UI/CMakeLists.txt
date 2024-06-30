cmake_minimum_required(VERSION 3.25.1)

add_subdirectory(widget)

add_library(UI "")

target_sources(UI
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/window.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/window.h
)

target_link_libraries(UI
  PRIVATE
    widget
)