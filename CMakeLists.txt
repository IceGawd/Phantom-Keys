cmake_minimum_required(VERSION 3.15)
project(PhantomKeys LANGUAGES C CXX)

# Default to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the build type (Debug or Release)" FORCE)
endif()

# C++ standard
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Directories
set(SRCDIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDEDIR "${CMAKE_SOURCE_DIR}/include")
set(SDLINCLUDEDIR "C:/SDL2/include")
set(SDLLIBDIR "C:/SDL2/lib")

# Include and link directories
include_directories(${INCLUDEDIR} ${SDLINCLUDEDIR})
link_directories(${SDLLIBDIR})

# Gather source files
file(GLOB_RECURSE SOURCES "${SRCDIR}/*.cpp" "${SRCDIR}/*.c" "${SRCDIR}/detail/*.cpp")

# Create executable
add_executable(main ${SOURCES})

# Link SDL2
target_link_libraries(main mingw32 SDL2main SDL2 SDL2_image SDL2_ttf SDL2_mixer)

# Debug/Release-specific settings
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building Debug with AddressSanitizer and full debug info")
    target_compile_options(main PRIVATE -O0 -g3)
    target_link_options(main PRIVATE)
else()
    message(STATUS "Building Release with optimizations")
    target_compile_options(main PRIVATE -O3)
endif()
