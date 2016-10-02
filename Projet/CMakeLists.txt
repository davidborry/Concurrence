cmake_minimum_required(VERSION 2.8.4)
project(Projet)

add_definitions(-std=gnu++0x)

set(MAIN main.cpp)
add_executable(simulation ${MAIN})

include_directories(project)

add_subdirectory(project)
add_subdirectory(tests)

target_link_libraries(simulation project)