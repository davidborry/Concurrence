
set(SOURCE_FILES include/Map.h include/Cell.h source/Cell.cpp source/Map.cpp include/World.h include/Entity.h include/DataTable.h source/DataTable.cpp source/Entity.cpp source/options.cpp include/options.h source/validate_options.cpp include/validate_options.h source/World.cpp include/Simulation.h include/MTSim1.h include/MTSim2.h source/Simulation.cpp source/MTSim1.cpp source/MTSim2.cpp include/Measures.h source/Measures.cpp)
add_library(project ${SOURCE_FILES})

