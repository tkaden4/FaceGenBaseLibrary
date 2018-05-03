cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(LibFgNix)

file(GLOB SOURCES "*.cpp")

add_library(LibFgNix STATIC ${SOURCES})

target_include_directories(LibFgNix PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	../LibFgBase/src/
	../LibTpBoost/boost_1_66_0/)
