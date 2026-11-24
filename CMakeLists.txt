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

# 1. Include Geode's core CMake definitions to load `add_geode_mod`
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

# 2. Define the mod target using Geode v5's native macro
add_geode_mod(${PROJECT_NAME}
    src/main.cpp
)
