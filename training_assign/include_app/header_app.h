#ifndef HEADER_APP
#define HEADER_APP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void sigintHandler(int sig_num);
void execute_command(char* main_mode);

#endif