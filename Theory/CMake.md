<h1 style="text-align:center">CMake Tutorial </h1>

### 1. Steps to practive with CMake

#### **Step 1:** Seperate file to folders

- source folder: contain the main file, c file: main.c, sum.c,..
- include: contain the header file: main.h,..
- build: where build file
- Common tree:
  - root:
    - CmakeLists.txt
    - App:
      - source app: .c
      - include file: .h
      - CmakeLists.txt
    - Library:
      - source lib: .c
      - include file: .h
      - CMakeList.txt
    - Build:
      - CMakeFile
      - Makefile

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
- **cmake_minimum_required (VERSION 2.6)**: sets minimum version of cmake to be used
- **project(Name)**: set project name
- **find_package(PkgConfig)**: Find an external project, and load its settings
- **pkg_check_modules(GLESv2 glesv2 REQUIRED)**: OpenGL ES
- **add_executable**: build app
- **add_library**: build a target library from source files
- **find_program(WAYLAND_SCANNER_EXECUTABLE NAMES wayland-scanner)**: find program
- **add_custom_command**: generating build file from xml file
- add_custom_command(
    OUTPUT  ivi-application-protocol.c
    COMMAND ${WAYLAND_SCANNER_EXECUTABLE} code
            < ${CMAKE_SOURCE_DIR}/protocol/ivi-application.xml          #input
            > ${CMAKE_CURRENT_BINARY_DIR}/ivi-application-protocol.c    #output
    DEPENDS ${CMAKE_SOURCE_DIR}/protocol/ivi-application.xml            #depend
)
- **include_directories**:Add include directories to the build
include_directories(
    ${GLESv2_INCLUDE_DIRS}
)
- **link_directories**: Add directories in which the linker will look for libraries
- **add_subdirectory**: adds a subdirectory to build
- **add_dependencies**: add target_dependencies
- **target_link_libraries**: link object file to library
- **install**: install a target to destination path
- install (TARGETS EGLWL_Input_Event DESTINATION bin)
