cmake_minimum_required(VERSION 2.8)

project(Snake)

file(GLOB SOURCES "src/*.cpp")

add_executable(Snake ${SOURCES})

target_include_directories(Snake PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)