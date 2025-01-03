# msvc_toolchain.cmake
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER cl)
set(CMAKE_CXX_COMPILER cl)
message(STATUS "Toolchain: Using MSVC")
