cmake_minimum_required(VERSION 3.16)

project(cs_sdk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# output klasörleri
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# include klasörü
include_directories(include)

# =========================
# SDK LIBRARY
# =========================

add_library(cs_sdk SHARED
    src/sdk.cpp
    src/plugin_manager.cpp
)

# =========================
# EXAMPLE PLUGIN
# =========================

add_library(example_plugin SHARED
    plugins/example_plugin.cpp
)

target_link_libraries(example_plugin cs_sdk)

# macOS lib prefix kaldır (example_plugin.dylib olsun)
set_target_properties(example_plugin PROPERTIES PREFIX "")

# =========================
# ENGINE EXECUTABLE
# =========================

add_executable(engine
    main.cpp
)

target_link_libraries(engine cs_sdk)

# =========================
# macOS dynamic loading
# =========================

if(APPLE)
    target_link_libraries(cs_sdk dl)
endif()
