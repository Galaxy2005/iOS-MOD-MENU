cmake_minimum_required(VERSION 3.21)
project(ios-mod-menu VERSION 1.0.0)

find_package(Geode REQUIRED)

add_geode_mod(${PROJECT_NAME}
    src/main.cpp
)

# Explicitly target include directories so Geode loader and FMOD headers are resolved properly on iOS
target_include_directories(${PROJECT_NAME} PRIVATE
    ${Geode_INCLUDE_DIR}
    ${Geode_INCLUDE_DIR}/Geode/fmod
)
