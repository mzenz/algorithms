cmake_minimum_required(VERSION 3.10)

project(hash)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# enable debug symbols
set(CMAKE_CXX_FLAGS_DEBUG "-g")

add_executable(hash main.cpp)
