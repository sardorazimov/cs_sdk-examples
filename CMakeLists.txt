cmake_minimum_required(VERSION 3.15)
project(CustomGameSDK)

set(CMAKE_CXX_STANDARD 20)

add_library(sdk
    src/sdk.cpp
    src/events.cpp
    src/plugin_loader.cpp
)

target_include_directories(sdk PUBLIC include)
