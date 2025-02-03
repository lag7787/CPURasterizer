cmake_minimum_required(VERSION 3.10)
project(rasterizer VERSION 1.0)

set(SOURCE_FILE1 src/main.cpp)
set(SOURCE_FILE2 src/geometry.cpp)
set(SOURCE_FILE3 src/test.cpp)

add_executable(rasterizer ${SOURCE_FILE1} ${SOURCE_FILE2} ${SOURCE_FILE3})
target_include_directories(rasterizer PUBLIC ${PROJECT_SOURCE_DIR}/include)
