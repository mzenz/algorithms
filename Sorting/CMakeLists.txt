cmake_minimum_required(VERSION 3.10)

project(sort)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Enable debug symbols for LLDB
set(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(sort main.cpp)
