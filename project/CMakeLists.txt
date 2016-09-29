
set(SOURCE_FILES main.cpp include/Map.h include/Cell.h source/Cell.cpp source/Map.cpp include/World.h include/Entity.h include/DataTable.h source/DataTable.cpp source/Entity.cpp)
add_library(SOURCE ${SOURCE_FILES})
add_executable(exe main.cpp)

target_link_libraries(exe SOURCE)