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

# Bring in Geode SDK subdirectory
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Define your mod target
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# Add FMOD include directories directly to the target safely without keyword mixups
target_include_directories(${PROJECT_NAME} PRIVATE
    $ENV{GEODE_SDK}/loader/include/Geode/fmod
)

# Let Geode handle setup and linking entirely
setup_geode_mod(${PROJECT_NAME})
