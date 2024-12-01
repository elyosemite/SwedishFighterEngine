cmake_minimum_required(VERSION 3.30)

project(SwedishFighterEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src/MissileTrajectoryCalculation)
add_subdirectory(src/alpha)

add_executable(${PROJECT_NAME} Engine.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC MissileTrajectoryCalculation)
target_link_libraries(${PROJECT_NAME} PUBLIC Alpha)

target_include_directories(${PROJECT_NAME} PUBLIC 
                      "${PROJECT_BINARY_DIR}"
                      "${PROJECT_SOURCE_DIR}/src/MissileTrajectoryCalculation"
                      "${PROJECT_SOURCE_DIR}/src/alpha/include",
                      "${PROJECT_SOURCE_DIR}/include")
