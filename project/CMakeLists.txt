
set(SOURCE_FILES main.cpp include/Map.h include/Cell.h source/Cell.cpp source/Map.cpp)
add_library(SOURCE ${SOURCE_FILES})
add_executable(exe main.cpp)

target_link_libraries(exe SOURCE)