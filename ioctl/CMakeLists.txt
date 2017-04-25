# ------------------------------------------------------------------------------
# CMake Includes
# ------------------------------------------------------------------------------

include("${CMAKE_INSTALL_PREFIX}/cmake/CMakeGlobal_Includes.txt")

# ------------------------------------------------------------------------------
# Exports
# ------------------------------------------------------------------------------

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DCOMPILING_IOCTL")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCOMPILING_IOCTL")

# ------------------------------------------------------------------------------
# Targets
# ------------------------------------------------------------------------------

if(NOT WIN32 STREQUAL "1")
    list(APPEND SOURCES
        arch/linux/ioctl.cpp
        arch/linux/ioctl_private.cpp
    )
    include_directories(arch/linux/)
else()
    list(APPEND SOURCES
        arch/windows/ioctl.cpp
        arch/windows/ioctl_private.cpp
    )
    include_directories(arch/windows/)
endif()

add_library(ioctl OBJECT ${SOURCES})
add_library(bfm_ioctl SHARED $<TARGET_OBJECTS:ioctl>)
add_library(bfm_ioctl_static STATIC $<TARGET_OBJECTS:ioctl>)

# ------------------------------------------------------------------------------
# Install
# ------------------------------------------------------------------------------

install(TARGETS bfm_ioctl DESTINATION lib)
install(TARGETS bfm_ioctl_static DESTINATION lib)
