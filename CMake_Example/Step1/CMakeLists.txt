cmake_minimum_required(VERSION 3.16.3)

# set the project name
project(Tutorial VERSION 1.0)

#add the MathFunction library
add_subdirectory(MathFunctions)

if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

#add the executable
add_executable(Tutorial tutorial.c)

target_link_libraries(Tutorial PUBLIC $(EXTRA_LIBS))

option(USE_MYMATH "Use tutorial provided math inplementation" ON)

# configure a header file to pass some of the CMake settings to the source code#
configure_file(TutorialConfig.h.in TutorialConfig.h)

target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )
        


