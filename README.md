# libstr - C99 string library

This project aims at implementing a **free**, simple and not too slow implementation of a **dynamic string in C99**. It is targeted towards education, but can be used freely in other projects, as its license is a simple MIT license.

## 1. Build
To build `libstr`, you need a **C99-compliant C compiler**, with **CMake** installed on your system. There is no inherent prerequisite, as `libstr` uses only C standard library components.  

To build `libstr`, create an empty directory called `build`, and switch to it. Then, when inside, run `cmake -B . -S ..` to generate the build files. To build using the generated configuration, run `cmake --build .`.  

If your project already uses CMake, you only need to add this project directory as a subdirectory, and the build system will take care of building everything to you. Make sure to specify linking between executables and libraries, otherwise it will throw linking errors.