# gcc_toolchain.cmake
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_C_COMPILER g++)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_MAKE_PROGRAM mingw32-make)
message(STATUS "Toolchain: Using GCC/G++")
