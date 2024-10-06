# Criar uma biblioteca para o módulo 1
add_library(MissileTrajectoryCalculation STATIC Missile.cpp)

# Incluir diretórios de cabeçalhos (se necessário)
target_include_directories(MissileTrajectoryCalculation PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Definir dependências de bibliotecas (se houver)
# target_link_libraries(module1 PUBLIC some_external_library)
