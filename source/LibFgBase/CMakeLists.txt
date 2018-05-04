cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(LibFgBase CXX C)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

if(UNIX)
	add_definitions("-DBOOST_THREAD_POSIX")
endif()

add_library(LibFgBase STATIC ${SOURCES})

target_include_directories(LibFgBase PUBLIC src)
target_link_libraries(LibFgBase
	PRIVATE LibImageMagickCore
	PRIVATE LibTpBoost
	PRIVATE LibTntJama
	PRIVATE LibJpegIjg6b
	PRIVATE LibUTF-8)
