cmake_minimum_required(VERSION 3.30)

project(SwedishFighterEngine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Options for the Compiler
option(USE_GCC "GCC Compiler" ON)
option(USE_MSVC "MSVC Compiler" OFF)
option(USE_CLANG "Clang Compiler" OFF)

if(USE_GCC)
    include(${CMAKE_SOURCE_DIR}/cmake/toolchain-mingw.cmake)
elseif(USE_MSVC)
    include(${CMAKE_SOURCE_DIR}/cmake/toolchain-msvc.cmake)
elseif(USE_CLANG)
    include(${CMAKE_SOURCE_DIR}/cmake/toolchain-clang.cmake)
else()
    message(WARNING "Nenhuma opção de compilador selecionada. Usando o padrão do sistema.")
endif()

add_subdirectory(src/MissileTrajectoryCalculation)
add_subdirectory(src/alpha)
add_subdirectory(src/beta)
add_subdirectory(src/gamma)

add_executable(${PROJECT_NAME} Engine.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC MissileTrajectoryCalculation)
target_link_libraries(${PROJECT_NAME} PUBLIC Alpha)
target_link_libraries(${PROJECT_NAME} PUBLIC Beta)
target_link_libraries(${PROJECT_NAME} PUBLIC Gamma)

target_include_directories(${PROJECT_NAME} PUBLIC 
                      "${PROJECT_BINARY_DIR}"
                      "${PROJECT_SOURCE_DIR}/src/MissileTrajectoryCalculation")
