# gcc_toolchain.cmake
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_MAKE_PROGRAM mingw32-make)

# Defining common options to GCC
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

# Default System C++ Version
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Toolchain: Using GCC/G++")
