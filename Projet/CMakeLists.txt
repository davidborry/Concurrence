cmake_minimum_required(VERSION 2.8.4)
project(Projet)

add_definitions(-std=c++11)
find_package (Threads)

set(MAIN src/project/main.cpp)
add_executable(simulation ${MAIN})

include_directories(src/project)

add_subdirectory(src/project)
add_subdirectory(src/tests)

target_link_libraries(simulation project)
target_link_libraries (simulation ${CMAKE_THREAD_LIBS_INIT})