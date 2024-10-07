add_library(MissileTrajectoryCalculation STATIC Missile.cpp)

target_include_directories(MissileTrajectoryCalculation PUBLIC ${PROJECT_SOURCE_DIR}/include)
