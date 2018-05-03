cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(LibFgBase CXX C)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

add_library(LibFgBase STATIC ${SOURCES})

target_include_directories(LibFgBase PUBLIC src)
target_link_libraries(LibFgBase
	PRIVATE LibImageMagickCore
	PRIVATE LibTpBoost
	PRIVATE LibTntJama
	PRIVATE LibJpegIjg6b
	PRIVATE LibUTF-8)
