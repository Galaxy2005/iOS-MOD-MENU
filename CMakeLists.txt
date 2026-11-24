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

# 1. Bring in the Geode SDK subdirectory to load its macros and targets
add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# 2. Use Geode v5's native macro to define the mod target and source files cleanly
add_geode_mod(${PROJECT_NAME}
    src/main.cpp
)
```[span_1](start_span)[span_1](end_span)

### Next Steps:
1. Save and commit this updated `CMakeLists.txt` to your repository[span_2](start_span)[span_2](end_span).
2. Go to your GitHub **Actions** tab and re-run your workflow[span_3](start_span)[span_3](end_span). 

Using `add_geode_mod` directly after `add_subdirectory` will allow Geode to fully manage bindings, FMOD types, and iOS compilation without signature conflicts[span_4](start_span)[span_4](end_span)!
