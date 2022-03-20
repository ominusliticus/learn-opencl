# 
# Author: Kevin Ingles
# File: CMakeLists.txt (top directory)
# Description: Top CMakeLists file for this project

cmake_minimum_required(VERSION 3.17)
set(CMAKE_FIND_DEBUG_MODE OFF)

project(
    HelloOpenCL
    VERSION 0.1
    LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-O3")

find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIR})

set(HelloOpenCL_src
    main.cpp
)

add_executable(HelloOpenCL_x ${HelloOpenCL_src})

target_link_libraries(HelloOpenCL_x
    PUBLIC
    ${OpenCL_LIBRARIES}
)
