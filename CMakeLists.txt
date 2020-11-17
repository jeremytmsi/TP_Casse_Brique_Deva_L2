cmake_minimum_required(VERSION 3.16)
project(TP C)

set(CMAKE_C_STANDARD 11)

set(SDL2_INCLUDE_DIR include/SDL2/)
set(SDL2_LIB_DIR lib/SDL2/)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_executable(TP main.c)
    target_link_libraries(${PROJECT_NAME} -lSDL2main -lSDL2)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_executable(TP main.c)
    target_link_libraries(${PROJECT_NAME} -lmingw32 -lSDL2main -lSDL2)
endif()