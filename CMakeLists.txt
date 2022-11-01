cmake_minimum_required(VERSION 3.12)
project(libstr C)

set(CMAKE_C_STANDARD_REQUIRED 99)
set(CMAKE_C_STANDARD 99)

if (MSVC)
    set(CMAKE_C_FLAGS_DEBUG "/Od /Z7")
    set(CMAKE_C_FLAGS_RELEASE "/O3")
else()
    set(CMAKE_C_FLAGS_DEBUG "-g -O0")
    set(CMAKE_C_FLAGS_RELEASE "-Os")
endif()

include_directories(include)

add_library(str STATIC
    "include/libstr.h"
    "src/libstr.c"
)