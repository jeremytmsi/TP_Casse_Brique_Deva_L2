cmake_minimum_required(VERSION 3.16)
project(TP C)

set(CMAKE_C_STANDARD 11)

set(SDL2_INCLUDE_DIR include/SDL2/)
set(SDL2_LIB_DIR lib/SDL2/)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(TP main.c)
target_link_libraries(${PROJECT_NAME} SDL2main SDL2)