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

# Bring in the Geode SDK subdirectory first so its targets and variables initialize
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# Globally force FMOD headers and loader include paths for both your mod and generated bindings
add_compile_options(
    -I$ENV{GEODE_SDK}/loader/include
    -I$ENV{GEODE_SDK}/loader/include/Geode/fmod
    -I$ENV{GEODE_SDK}/loader/include/Geode/cocos/include
)

include_directories(
    $ENV{GEODE_SDK}/loader/include
    $ENV{GEODE_SDK}/loader/include/Geode/fmod
)

setup_geode_mod(${PROJECT_NAME})
