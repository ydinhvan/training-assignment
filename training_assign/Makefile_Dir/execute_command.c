#include "lib_training_exam.h"

// function of mode 1: execute commnad
void execute_command(char* main_mode)
{
    /* Ask user for command. */
    printf("Type command you want to execute: ");
    // Mallo memory to save input command
    char *input_command = (char*)malloc(256);
    if (input_command == NULL)
    {
        printf("No memory\n");
        return;
    }
    /* Get the name, with size limit. */
    fgets(input_command, 256 , stdin);
    /* Remove trailing newline, if there. */
    if ((strlen(input_command) > 0) && (input_command[strlen (input_command) - 1] == '\n'))
    {
        input_command[strlen (input_command) - 1] = '\0';
    }
    // get data from stdin buffer and move to input_command
    fgets(input_command, 256 , stdin);
    /* Excute command */
    system(input_command);
    /* Free memory and exit. */
    free (input_command);
    printf("\n");

    printf("Command executed! Type 'c' to continue, random to back: ");

    scanf("%c",main_mode);
    // check condition to continue or break
    if(*main_mode=='c')
    {
        execute_command(main_mode);
    }
        
}