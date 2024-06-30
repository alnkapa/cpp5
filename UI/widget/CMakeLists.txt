cmake_minimum_required(VERSION 3.25.1)

add_library(widget "")


target_sources(widget
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/widget.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/widget.h
)

