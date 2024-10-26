cmake_minimum_required(VERSION 3.15...3.30)

project(dsa_cpp VERSION 1.0
                  DESCRIPTION "DSA in C++"
                  LANGUAGES CXX)

# 包含 include 目录中的头文件
include_directories(${PROJECT_SOURCE_DIR}/include)
                  
# 查找源文件
file(GLOB SOURCES "src/*.cpp")

# 定义输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# 添加可执行文件
add_executable(dsa_cpp ${SOURCES})
