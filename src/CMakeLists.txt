# ------------------------------------------------------------------------------
# CMake Includes
# ------------------------------------------------------------------------------

include("${CMAKE_INSTALL_PREFIX}/cmake/CMakeGlobal_Includes.txt")

# ------------------------------------------------------------------------------
# Exports
# ------------------------------------------------------------------------------

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCOMPILING_BFMSRC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCOMPILING_BFMSRC")

# ------------------------------------------------------------------------------
# Targets
# ------------------------------------------------------------------------------

list(APPEND SOURCES
    command_line_parser.cpp
    ioctl_driver.cpp
    ${CMAKE_INSTALL_PREFIX}/src/bfvmcall_intel_x64.asm
)

add_library(obj OBJECT ${SOURCES})
add_library(bfm_src SHARED $<TARGET_OBJECTS:obj>)
add_library(bfm_src_static STATIC $<TARGET_OBJECTS:obj>)
