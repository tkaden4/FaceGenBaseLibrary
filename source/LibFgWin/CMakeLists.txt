cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(LibFgWin)

file(GLOB SOURCES "*.cpp")

add_library(LibFgWin STATIC ${SOURCES})

target_include_directories(LibFgWin PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	../LibFgBase/src/
	../LibTpBoost/boost_1_66_0/)
