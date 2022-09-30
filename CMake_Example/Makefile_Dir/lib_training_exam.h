#ifndef LIB_TRAINING_EXAM
#define LIB_TRAINING_EXAM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h> 

void sigintHandler(int sig_num);
void execute_command(char* main_mode);
void lib_read_write();

#endif