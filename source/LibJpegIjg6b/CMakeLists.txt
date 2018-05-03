cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(LibJpegIjg6b C)

file(GLOB SOURCES "*.c")

add_library(LibJpegIjg6b STATIC ${SOURCES})

target_include_directories(LibJpegIjg6b PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
