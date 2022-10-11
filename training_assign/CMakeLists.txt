# Require minimum cmake version
cmake_minimum_required(VERSION 3.16.3)

# App name and standard C
project(App C)

# Include directory contain header file
include_directories(include_lib)

# Include directory contain header file
include_directories(include_app)

add_subdirectory(src_lib)
# 
add_subdirectory(src_app)



