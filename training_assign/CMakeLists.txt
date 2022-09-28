# Require minimum cmake version
cmake_minimum_required(VERSION 3.16.3)

# App name and standard C
project(training_exam_app C)

# Include directory contain header file
include_directories(include)

# add file depend 
add_executable(training_exam_app src/main.c src/execute_command.c
               src/read_write.c  src/signal_handler.c)


