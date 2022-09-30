<h1 style="text-align:center">CMake Tutorial </h1>

### 1. Steps to practive with CMake
#### **Step 1:** Seperate file to folders:
- source folder: contain the main file, c file: main.c, sum.c,..
- include: contain the header file: main.h,..
- build: where build file
- Tree map
  - root: 
    - CmakeLists.txt
    - Source file: 
        - main.c
        - sum.c
        ...
    - Include file:
        - main.h
        ...
    - Build:
        - CMakeFile
        - Makefile
        ...

#### **Step 2:** Write CMakeLists.txt
cmake_minimum_required(VERSION 3.16.3)
// cmake --version in terminal to know version

project(TARGET C)
// Ex: project(myproject C)

include_directories(directory)
// Ex: include_directories(include)

add_executable(TARGET source_file)
// Ex: add_executable(myproject src/main.c src/sum.c)

#### **Step 3:** Connect compiler, generate Cmake
- **cd build**: go to build directory, where will contain involve file of Cmake: CMakeFiles, CMakeCache.txt,...
- **cmake ../**: run Cmake to configure the project and generate build system

#### **Step 4:** Makefile
- make: execute make file, generate target file

### 2. Function in CMakeLists.txt

### 3. Some commonly used command
- **message**: prints given message
- **cmake_minimum_required**: sets minimum version of cmake to be used
- **add_executable**: adds executable target with given name
- **add_library**: adds a library target to be build from listed source files
- **add_subdirectory**: adds a subdirectory to build