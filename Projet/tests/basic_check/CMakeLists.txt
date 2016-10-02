include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(simpleTest basic_test.cpp)

target_link_libraries(simpleTest gtest gtest_main)
target_link_libraries(simpleTest project)