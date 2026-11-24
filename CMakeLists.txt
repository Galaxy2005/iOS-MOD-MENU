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

# 1. Bring in the Geode SDK subdirectory first
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# 2. Define your mod library target
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# 3. Explicitly add include directories for loader and FMOD headers to your target
target_include_directories(${PROJECT_NAME} PRIVATE
    $ENV{GEODE_SDK}/loader/include
    $ENV{GEODE_SDK}/loader/include/Geode/fmod
    $ENV{GEODE_SDK}/loader/include/Geode/cocos/include
    $ENV{GEODE_SDK}/loader/include/Geode/cocos/extensions
)

# 4. Let Geode handle packaging, bindings, and setup macro
setup_geode_mod(${PROJECT_NAME})
