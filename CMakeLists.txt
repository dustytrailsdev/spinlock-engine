cmake_minimum_required(VERSION 3.20)
project(spinlock-engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_library(spinlock STATIC src/build.cpp)
target_include_directories(spinlock PUBLIC "${CMAKE_SOURCE_DIR}/src")

add_executable(test_main test/test_main.cpp)
target_link_libraries(test_main PRIVATE spinlock)
