cmake_minimum_required(VERSION 2.8.4)
project(Projet)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


include_directories(project)

add_subdirectory(project)
add_subdirectory(tests)

