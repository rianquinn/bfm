# ------------------------------------------------------------------------------
# CMake Includes
# ------------------------------------------------------------------------------

include("${CMAKE_INSTALL_PREFIX}/cmake/CMakeGlobal_Includes.txt")

# ------------------------------------------------------------------------------
# Flags
# ------------------------------------------------------------------------------

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCMAKE_INSTALL_PREFIX=\\\"${CMAKE_INSTALL_PREFIX}\\\"")

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

add_library(bfm_ioctl SHARED ${SOURCES})
add_library(bfm_ioctl_static STATIC ${SOURCES})

target_compile_definitions(bfm_ioctl PRIVATE SHARED_BFM_IOCTL)
target_compile_definitions(bfm_ioctl_static PUBLIC STATIC_BFM_IOCTL)

# ------------------------------------------------------------------------------
# Install
# ------------------------------------------------------------------------------

install(TARGETS bfm_ioctl DESTINATION lib)
install(TARGETS bfm_ioctl_static DESTINATION lib)
