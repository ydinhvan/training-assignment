cmake_minimum_required(VERSION 3.16.3)

#add the MathFunctions add_library
add_subdirectory(MathFunctions)

# set the project name
project(Tutorial VERSION 1.0)







if(USE_MY_MATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()

# add the executable
add_executable(Tutorial Tutorial.c)

target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path foe include files
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}
                           )