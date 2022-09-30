#include <stdio.h>
#include <stdbool.h> 
#include "header_app.h"
#include "header_lib.h"


void intinial_func();

int main( int argc, char *argv[] )
{
    // ignore interrupt signal
    signal(SIGINT, sigintHandler);
    
    //clear console
    system("clear");
    // ignore inttraining_exam_appput variation
    char main_mode;

    // intinial program
    intinial_func();
    
    while(1)         // If Ctrl+C isn't pressed
    {
        //Type input mode
        scanf("%s",&main_mode);
        // Skip if main_mode ='\n'
        if (main_mode == '\n')
        {
            continue;
        }
        // print main_mode
        printf("You chose mode: %c\n",main_mode);
        if (main_mode == '1')
        {
            // mode 1: execute command
            execute_command(&main_mode);
            main_mode = '\0';
            intinial_func();
            fflush(stdout);
        }
        else if (main_mode == '2')
        {
            // mode 2: read/write file
            lib_read_write();
            main_mode = '\0';
            intinial_func();
        }
        else 
        {
            printf("Type error -> Please type again!\n");
        }
    }
    return 0;
}





// Intinial function: print instructions
void intinial_func()
{
    printf("\nApplication has 2 mode: Read/Write and execute a command\n");
    printf("Type '1' to choice execute command mode\n");
    printf("Type '2' to choice read/write mode\n");
}