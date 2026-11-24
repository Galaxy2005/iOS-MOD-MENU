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

# 1. Bring in the Geode SDK subdirectory first so its variables/targets initialize
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# 2. Set directory-level include paths so both target and subtargets inherit FMOD and loader headers
include_directories(
    $ENV{GEODE_SDK}/loader/include
    $ENV{GEODE_SDK}/loader/include/Geode/fmod
)

# 3. Define your mod target library
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# 4. Setup the Geode mod
setup_geode_mod(${PROJECT_NAME})
