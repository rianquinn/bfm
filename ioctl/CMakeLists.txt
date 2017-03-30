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
else()
    list(APPEND SOURCES
        arch/windows/ioctl.cpp
        arch/windows/ioctl_private.cpp
    )
endif()

add_library(ioctl OBJECT ${SOURCES})
add_library(bfm_ioctl SHARED $<TARGET_OBJECTS:ioctl>)
add_library(bfm_ioctl_static STATIC $<TARGET_OBJECTS:ioctl>)

target_link_libraries(bfvmm_exit_handler bfvmm_intrinsics)
target_link_libraries(bfvmm_exit_handler bfvmm_memory_manager)
target_link_libraries(bfvmm_exit_handler bfvmm_vmcs)

# ------------------------------------------------------------------------------
# Install
# ------------------------------------------------------------------------------

if(CMAKE_TOOLCHAIN_FILE)
    install(TARGETS bfvmm_exit_handler DESTINATION ${BAREFLANK_SYSROOT_PATH}/lib)
    install(TARGETS bfvmm_exit_handler_static DESTINATION ${BAREFLANK_SYSROOT_PATH}/lib)
endif()
