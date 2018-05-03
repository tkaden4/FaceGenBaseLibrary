cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(magick C)
 
file(GLOB SOURCES "*.c")

add_library(magick INTERFACE)

message(STATUS "${CMAKE_CURRENT_SOURCE_DIR}/../")

target_sources(magick INTERFACE ${SOURCES})
target_include_directories(magick INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../)
