cmake_minimum_required(VERSION 3.25.1)

add_library(event "")

target_sources(event
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/event.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/event.h
)
