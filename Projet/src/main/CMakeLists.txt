
set(SOURCE_FILES include/Zone.h source/Zone.cpp include/FullSyncEntity.h source/FullSyncEntity.cpp include/Map.h include/Cell.h source/Cell.cpp source/Map.cpp include/World.h include/Entity.h include/DataTable.h source/DataTable.cpp source/Entity.cpp source/options.cpp include/options.h source/validate_options.cpp include/validate_options.h source/World.cpp include/STSim.h include/MTSim2.h include/MTSim1.h source/STSim.cpp source/MTSim2.cpp source/MTSim1.cpp include/Measures.h source/Measures.cpp include/Simulation.h source/Simulation.cpp include/RegionSyncEntity.h source/RegionSyncEntity.cpp)
add_library(project ${SOURCE_FILES})

