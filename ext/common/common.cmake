# Picasso - a vector graphics library
# 
# Copyright (C) 2024 Zhang Ji Peng
# Contact: onecoolx@gmail.com

set(PXCOMMON_DIR ${PROJECT_ROOT}/ext/common)

set(PXCOMMON_SOURCES
    ${PXCOMMON_DIR}/psx_linear_allocator.h
    ${PXCOMMON_DIR}/psx_linear_allocator.c
)

set(LIBX_COMMON psx_common)

add_library(${LIBX_COMMON} STATIC ${PXCOMMON_SOURCES})
if (UNIX AND NOT APPLE)
    include(GNUInstallDirs)
    install(TARGETS ${LIBX_COMMON} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/picasso ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/picasso)
else
    install(TARGETS ${LIBX_COMMON} LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
endif
include_directories(${PXCOMMON_DIR} ${PROJECT_ROOT}/ext/common)

