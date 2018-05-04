cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(LibTpBoost CXX)

set(CMAKE_CXX_STANDARD 11)

add_definitions("-DBOOST_THREAD_BUILD_LIB=1 -DBOOST_ALL_NO_LIB -DBOOST_THREAD_USE_LIB=1")

if(WIN32)
	add_definitions(-DBOOST_THREAD_POSIX)
elseif()

set(LIBS_ROOT "boost_1_66_0/libs")

file(GLOB_RECURSE SOURCES
	"${LIBS_ROOT}/date_time/src/*.cpp"
	"${LIBS_ROOT}/filesystem/src/*.cpp"
	"${LIBS_ROOT}/serialization/src/*.cpp"
	"${LIBS_ROOT}/system/src/*.cpp"
)

# Get boost_thread sources

set(THREAD_ROOT ${LIBS_ROOT}/thread)

if(WIN32)
	file(GLOB WIN_THREADS ${THREAD_ROOT}/src/win32/*.cpp)
	set(THREAD_SOURCES ${THREAD_SOURCES} ${WIN_THREADS})
endif(WIN32)
if(UNIX)
	file(GLOB PTHREADS ${THREAD_ROOT}/src/pthread/*.cpp)
	set(THREAD_SOURCES ${THREAD_SOURCES} ${PTHREADS})
endif(UNIX)

# end of threads

set(SOURCES ${SOURCES} ${THREAD_SOURCES})

add_library(LibTpBoost STATIC ${SOURCES})

target_include_directories(LibTpBoost PUBLIC boost_1_66_0/)
