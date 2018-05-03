cmake_minimum_required(VERSION 3.11)

project(LibTntJama C)

add_library(LibTntJama INTERFACE)

target_include_directories(LibTntJama INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
