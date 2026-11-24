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

# Explicitly set the FMOD directory cache variable for iOS bindings generation
set(GEODE_FMOD_INCLUDE_DIR "$ENV{GEODE_SDK}/loader/include/Geode/fmod" CACHE PATH "Path to FMOD headers" FORCE)

# Bring in the Geode SDK subdirectory
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Gather source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Define your mod target library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Let Geode handle target packaging, bindings, and linking
setup_geode_mod(${PROJECT_NAME})
