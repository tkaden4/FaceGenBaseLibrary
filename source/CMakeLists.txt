cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(fgbl CXX)

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

set(LIBRARIES
    PRIVATE LibFgBase
    PRIVATE pthread
    PRIVATE rt
)

if(UNIX)
    set(LIBRARIES ${LIBRARIES} PRIVATE LibFgNix)
elseif(WIN32)
    set(LIBRARIES ${LIBRARIES} PRIVATE LibFgWin)
endif()

target_link_libraries(fgbl ${LIBRARIES})
