# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.15)
# 项目信息
project(Leetcode)

set(CMAKE_CXX_STANDARD 11)

# include路径
include_directories(${PROJECT_SOURCE_DIR}/lib)

# 设置可执行文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("EXECUTABLE_OUTPUT_PATH:${EXECUTABLE_OUTPUT_PATH}")

# 生成debug版本
#SET(CMAKE_BUILD_TYPE "release")
SET(CMAKE_BUILD_TYPE "debug")
if (CMAKE_BUILD_TYPE STREQUAL debug)
    add_definitions(-D_DEBUG)
endif ()
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(
        ./leetCode
        DIR_SRCS_LeetCode)
aux_source_directory(
        ./ACM
        DIR_SRCS_ACM)

# 指定生成目标
add_executable(
        Leetcode
        leetCode/LeetCode895.cpp
#        test2.cpp
        )
