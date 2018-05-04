cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(LibFgNix)

file(GLOB SOURCES "*.cpp")

add_definitions("-DBOOST_ALL_NO_LIB -DBOOST_THREAD_USE_LIB=1 -DBOOST_THREAD_POSIX")

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wno-unused-result")
elseif(CMAKE_CXX_COMPILER_ID MATCHES Clang)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wno-unused-local-typedef")
endif()


add_library(LibFgNix STATIC ${SOURCES})

target_include_directories(LibFgNix PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	../LibFgBase/src/
	../LibTpBoost/boost_1_66_0/)
