cmake_minimum_required(VERSION 3.15)
project(ios-mod-menu)

find_package(Geode REQUIRED)

add_geode_mod(ios-mod-menu)

target_sources(ios-mod-menu PRIVATE
    src/main.cpp
)
