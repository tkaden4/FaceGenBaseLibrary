cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(LibImageMagickCore C)

set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/ImageMagick-6.6.2")

file(GLOB MAGICK_SOURCES
    "${PROJECT_ROOT}/bzlib/*.c"
    "${PROJECT_ROOT}/coders/*.c"
    "${PROJECT_ROOT}/jbig/libjbig/*.c"
    "${PROJECT_ROOT}/magick/*.c"
    "${PROJECT_ROOT}/png/*.c"
    "${PROJECT_ROOT}/xlib/*.c"
    "${PROJECT_ROOT}/zlib/*.c"
)

file(GLOB_RECURSE JASPER_SOURCES "${PROJECT_ROOT}/jp2/src/libjasper/*.c")

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

add_definitions(-w -D_MAGICKLIB -DTIFF_PLATFORM_CONSOLE -D_DEBUG)

if(UNIX)
    set(TIFF_SOURCES ${TIFF_SOURCES} ${TIFF_ROOT}tif_unix.c)
elseif(WIN32)
    set(TIFF_SOURCES ${TIFF_SOURCES} ${TIFF_ROOT}tif_win32.c)
endif()

add_library(LibImageMagickCore STATIC
    ${MAGICK_SOURCES}
    ${TIFF_SOURCES}
    ${JASPER_SOURCES})
# for libtiff

target_include_directories(LibImageMagickCore PUBLIC
    ${PROJECT_ROOT}
    ${PROJECT_ROOT}/bzlib/
    ${PROJECT_ROOT}/tiff/libtiff/
    ${PROJECT_ROOT}/zlib/
    ${PROJECT_ROOT}/xlib/
    ${PROJECT_ROOT}/jbig/libjbig/
    ${CMAKE_CURRENT_SOURCE_DIR}/../LibJpegIjg6b/
    ${PROJECT_ROOT}/jp2/src/libjasper/include/
    ${PROJECT_ROOT}/jp2/src/libjasper/include/jasper/
)
