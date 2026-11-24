cmake_minimum_required(VERSION 3.21)
project(ios-mod-menu VERSION 1.0.0)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable")
endif()

# Include Geode's core CMake setup module
include($ENV{GEODE_SDK}/cmake/Geode.cmake)

# Let Geode automatically create the target, handle PCH, include directories, and link dependencies
add_geode_mod(${PROJECT_NAME}
    src/main.cpp
)
