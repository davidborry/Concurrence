
enable_testing()
project(basictest)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runBasicTest
        basic_check/basic_test.cpp)

target_link_libraries(runBasicTest ${GTEST_LIBRARIES} pthread)
target_link_libraries(runBasicTest project)