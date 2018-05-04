cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(LibImageMagickCore C)

set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/ImageMagick-6.6.2")

add_definitions("-D_MAGICKLIB -DTIFF_PLATFORM_CONSOLE")

if(UNIX)
    add_definitions("-DBOOST_THREAD_POSIX")
endif()

if(CMAKE_C_COMPILER_ID MATCHES GNU)
    list(APPEND CMAKE_C_FLAGS "-w")
elseif(CMAKE_C_COMPILER_ID MATCHES Clang)
    list(APPEND CMAKE_C_FLAGS "-w")
elseif(CMAKE_C_COMPILER_ID MATCHES MSVC)
    list(APPEND CMAKE_C_FLAGS "/w")
endif()

# Generically gather sources
file(GLOB MAGICK_SOURCES
    "${PROJECT_ROOT}/bzlib/*.c"
    "${PROJECT_ROOT}/coders/*.c"
    "${PROJECT_ROOT}/jbig/libjbig/*.c"
    "${PROJECT_ROOT}/magick/*.c"
    "${PROJECT_ROOT}/png/*.c"
    "${PROJECT_ROOT}/zlib/*.c"
)

# Gather libjasper sources
file(GLOB_RECURSE JASPER_SOURCES "${PROJECT_ROOT}/jp2/src/libjasper/*.c")

# Gather libtiff sources
set(TIFF_ROOT ${PROJECT_ROOT}/tiff/libtiff/)
set(TIFF_SOURCES
    ${TIFF_ROOT}tif_aux.c
    ${TIFF_ROOT}tif_close.c
    ${TIFF_ROOT}tif_codec.c
    ${TIFF_ROOT}tif_color.c
    ${TIFF_ROOT}tif_compress.c
    ${TIFF_ROOT}tif_dir.c
    ${TIFF_ROOT}tif_dirinfo.c
    ${TIFF_ROOT}tif_dirread.c
    ${TIFF_ROOT}tif_dirwrite.c
    ${TIFF_ROOT}tif_dumpmode.c
    ${TIFF_ROOT}tif_error.c
    ${TIFF_ROOT}tif_extension.c
    ${TIFF_ROOT}tif_flush.c
    ${TIFF_ROOT}tif_getimage.c
    ${TIFF_ROOT}tif_jpeg.c
    ${TIFF_ROOT}tif_luv.c
    ${TIFF_ROOT}tif_lzw.c
    ${TIFF_ROOT}tif_next.c
    ${TIFF_ROOT}tif_ojpeg.c
    ${TIFF_ROOT}tif_open.c
    ${TIFF_ROOT}tif_packbits.c
    ${TIFF_ROOT}tif_pixarlog.c
    ${TIFF_ROOT}tif_predict.c
    ${TIFF_ROOT}tif_print.c
    ${TIFF_ROOT}tif_read.c
    ${TIFF_ROOT}tif_strip.c
    ${TIFF_ROOT}tif_swab.c
    ${TIFF_ROOT}tif_thunder.c
    ${TIFF_ROOT}tif_tile.c
    ${TIFF_ROOT}tif_version.c
    ${TIFF_ROOT}tif_warning.c
    ${TIFF_ROOT}tif_write.c
    ${TIFF_ROOT}tif_zip.c
)

if(UNIX)
    set(TIFF_SOURCES ${TIFF_SOURCES} ${TIFF_ROOT}tif_unix.c)
    # get xlib sources
    file(GLOB XLIB_SOURCES "${PROJECT_ROOT}/xlib/*.c")
    list(APPEND MAGICK_SOURCES ${XLIB_SOURCES})
elseif(WIN32)
    set(TIFF_SOURCES ${TIFF_SOURCES} ${TIFF_ROOT}tif_win32.c)
endif()

add_library(LibImageMagickCore STATIC
    ${MAGICK_SOURCES}
    ${TIFF_SOURCES}
    ${JASPER_SOURCES})

target_include_directories(LibImageMagickCore PUBLIC
    ${PROJECT_ROOT}
    ${PROJECT_ROOT}/bzlib/
    ${PROJECT_ROOT}/tiff/libtiff/
    ${PROJECT_ROOT}/zlib/
    ${PROJECT_ROOT}/png/
    ${PROJECT_ROOT}/xlib/
    ${PROJECT_ROOT}/jbig/libjbig/
    ${CMAKE_CURRENT_SOURCE_DIR}/../LibJpegIjg6b/
    ${PROJECT_ROOT}/jp2/src/libjasper/include/
    ${PROJECT_ROOT}/jp2/src/libjasper/include/jasper/
)
