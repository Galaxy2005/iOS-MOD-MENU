cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64")

project(ios-mod-menu VERSION 1.0.0)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

# 1. Include the base loader directory and the fmod directory properly for all targets
include_directories(
    $ENV{GEODE_SDK}/loader/include
    $ENV{GEODE_SDK}/loader/include/Geode/fmod
)

# 2. Add the Geode SDK subdirectory
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# 3. Define your mod library
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# 4. Ensure target-specific include directories are cleanly added
target_include_directories(${PROJECT_NAME} PRIVATE
    $ENV{GEODE_SDK}/loader/include
    $ENV{GEODE_SDK}/loader/include/Geode/fmod
)

# 5. Let Geode handle the packaging and setup macro
setup_geode_mod(${PROJECT_NAME})
