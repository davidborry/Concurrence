include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(vectorTests vector_test.cpp)

target_link_libraries(vectorTests gtest gtest_main)
target_link_libraries(vectorTests project)