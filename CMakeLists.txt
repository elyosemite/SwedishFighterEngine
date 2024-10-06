cmake_minimum_required(VERSION 3.30)

project(SwedishFighterEngine VERSION 1.0 LANGUAGES CXX)

# Definir o padrão C++ e outras flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Definir o diretório de saída para binários
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Adicionar subdiretórios
add_subdirectory(MissileTrajectoryCalculation)

# Incluir todos os arquivos .cpp da pasta src
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")

# Adicionar diretórios de código-fonte e incluir bibliotecas
add_executable(${PROJECT_NAME} ${SOURCES})

# Adicionar diretórios de cabeçalhos
include_directories(${PROJECT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/MissileTrajectoryCalculation")

# Adicionar a biblioteca fmt
find_package(fmt CONFIG REQUIRED)

# Vincular a versão header-only, se for o caso
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only MissileTrajectoryCalculation)
