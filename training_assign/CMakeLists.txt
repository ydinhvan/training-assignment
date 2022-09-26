cmake_minimum_required(VERSION 3.16.3)

project(training_exam C)

include_directories(include)

add_executable(training_exam src/training_exam.c src/execute_command.c
src/read_write.c src/signal_handler.c)
