cmake_minimum_required(VERSION 2.6)

set(SOURCE_FILES ../../project/main.cpp ../../project/include/Map.h ../../project/include/Cell.h ../../project/source/Cell.cpp)
add_library(SOURCE ${SOURCE_FILES})


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runBasicTest basic_test.cpp)
target_link_libraries(runBasicTest ${GTEST_LIBRARIES} pthread)
target_link_libraries(runBasicTest SOURCE)