add_library(Alpha Alpha.cpp)

option(USE_ALPHAZONE "Alpha Strike Zone" ON)

if (USE_ALPHAZONE)
    target_compile_definitions(Alpha PRIVATE "USE_ALPHAZONE")
    
    add_library(AlphaZone STATIC alphazone.cpp)

    target_link_libraries(Alpha PRIVATE AlphaZone)

    target_include_directories(Alpha INTERFACE "../../include")
endif()
