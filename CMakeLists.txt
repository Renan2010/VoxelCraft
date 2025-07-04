# CMakeLists.txt
cmake_minimum_required(VERSION 4.0.1)

# Set the project name and version
project(SpeedCraft VERSION 0.0.1 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Find raylib package
find_package(raylib REQUIRED)
if (NOT raylib_FOUND)
    message(FATAL_ERROR "raylib not found. Please install it.")
endif()

# Compile the source files
add_executable(
    SpeedCraft 
    src/main.cpp
    src/camera.cpp
    src/crosshair.cpp
    src/render.cpp
    src/inventory.cpp
    src/voxel_picker.cpp
)
# Add include directories for raylib
target_include_directories(
    SpeedCraft PRIVATE
    ${CMAKE_SOURCE_DIR}/src/include
)
# Add Release and debug compile flags
target_compile_options(SpeedCraft PRIVATE
    # Release build flags
    $<$<CONFIG:RELEASE>:
        -O3
        -DNDEBUG
        -flto
        -fno-exceptions
        -fomit-frame-pointer 
        -fno-inline
    >
    # Debug build flags
    $<$<CONFIG:DEBUG>:
        -O0
        -flto
        -g
        -Wall
        -Wextra
        -fno-omit-frame-pointer
        -fno-inline
    >
)
# Set linker flags
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -flto")

# Link the raylib library
target_link_libraries(
    SpeedCraft
    PRIVATE
    raylib
)
