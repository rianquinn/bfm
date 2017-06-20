# ------------------------------------------------------------------------------
# CMake Includes
# ------------------------------------------------------------------------------

include(${CMAKE_INSTALL_PREFIX}/cmake/CMakeGlobal_Includes.txt)

# ------------------------------------------------------------------------------
# Targets
# ------------------------------------------------------------------------------

list(APPEND SOURCES
    command_line_parser.cpp
    ioctl_driver.cpp
    ${CMAKE_INSTALL_PREFIX}/src/bfvmcall_intel_x64.asm
)

add_library(bfm_src SHARED ${SOURCES})
add_library(bfm_src_static STATIC ${SOURCES})

target_compile_definitions(bfm_src PRIVATE SHARED_BFM_SRC)
target_compile_definitions(bfm_src_static PUBLIC STATIC_BFM_SRC)
