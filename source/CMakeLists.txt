cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(fgbl CXX)

set(CMAKE_CXX_STANDARD 11)

set(BIN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)

if(APPLE)
    set(PLATFORM_PATH osx)
elseif(UNIX)
    set(PLATFORM_PATH ubuntu)
elseif(WIN32)
    set(PLATFORM_PATH win32)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    # gcc debug flags
    set(CMAKE_CXX_FLAGS_DEBUG "$-w -D_DEBUG -m64 -fPIC -g -O0")
    set(CMAKE_CXX_FLAGS_RELEASE "$-w -m64 -fPIC -O3 -ffast-math")
    set(CONFIG gcc/64/)
elseif(CMAKE_CXX_COMPILER_ID MATCHES Clang)
    # clang debug flags
    set(CMAKE_CXX_FLAGS_DEBUG "-fno-common -ftemplate-depth=1024 -O0 -g -D_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-fno-common -ftemplate-depth=1024 -Ofast")
    set(CONFIG clang/64)
elseif(CMAKE_CXX_COMPILER_ID MATCHES Intel)
    set(CMAKE_CXX_FLAGS_DEBUG "-diag-disable=11074,11076 -mavx -g -D_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "-diag-disable=11074,11076 -mavx -Ofast")
    set(CONFIG icpc/64)
elseif(CMAKE_CXX_COMPILER_ID MATCHES MSVC)
    set(CMAKE_CXX_FLAGS "/w /DWIN32 /D_CRT_SECURE_NO_DEPRECATE=1 /D_SCL_SECURE_NO_DEPRECATE=1 /D_CRT_SECURE_NO_WARNINGS /D_LIB")
    if(PROJECT_TYPE_PURE_GUI)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_WINDOWS")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D_CONSOLE")
    endif()
    set(CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG")
    set(CMAKE_CXX_FLAGS_RELEASE "/DNDEBUG")
endif()

# Add postfix to output directory accordingly
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CONFIG ${CONFIG}/release)
elseif(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CONFIG ${CONFIG}/debug)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR}/${PLATFORM_PATH}/${CONFIG})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LIB_DIR}/${PLATFORM_PATH}/${CONFIG})

# Base is platform-agnostic
add_subdirectory(LibFgBase)

# Add specific subdirectories for platform
if(UNIX)
	add_subdirectory(LibFgNix)
elseif(WIN32)
	add_subdirectory(LibFgWin)
endif()

add_subdirectory(LibImageMagickCore)
add_subdirectory(LibJpegIjg6b)
add_subdirectory(LibTntJama)
add_subdirectory(LibTpBoost)
add_subdirectory(LibUTF-8)

add_executable(fgbl fgbl/fgbl.cpp)

set(LIBRARIES PRIVATE LibFgBase)

if(UNIX)
    set(LIBRARIES ${LIBRARIES}
        PRIVATE LibFgNix
        PRIVATE pthread
        PRIVATE rt)
elseif(WIN32)
    set(LIBRARIES ${LIBRARIES}
        PRIVATE LibFgWin)
endif()

target_link_libraries(fgbl ${LIBRARIES})
