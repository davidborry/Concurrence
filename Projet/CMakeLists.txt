cmake_minimum_required(VERSION 2.8.4)
project(Projet)

add_definitions(-std=c++11)
find_package (Threads)

set(MAIN src/main/main.cpp)
add_executable(simulation ${MAIN})

include_directories(src/main)

add_subdirectory(src/main)
add_subdirectory(tests)

target_link_libraries(simulation project)
target_link_libraries (simulation ${CMAKE_THREAD_LIBS_INIT})