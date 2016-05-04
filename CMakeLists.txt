cmake_minimum_required(VERSION 2.6)

#set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g")

project(ZYThreadPool)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 指定头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
message(STATUS "project-dir:${PROJECT_SOURCE_DIR}")

# 添加子目录
add_subdirectory(src)
add_subdirectory(test)
