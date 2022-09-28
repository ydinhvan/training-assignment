#include "lib_training_exam.h"

// function of mode 1: execute commnad
void execute_command(char* main_mode)
{
    // Malloc memory to save input command
    char *input_command = (char*)malloc(256);
    // check if input_command point to NULL
    if (input_command == NULL)
    {
        printf("No memory\n");
        return;
    }
    /* Get the name, with size limit. */
    fgets(input_command, 256 , stdin);
    // Get string from stdin: input_command = \n
    // Because after type 1, press enter = '\n' in stdin buffer
    
    /* Remove trailing newline, if there. */
    if ((strlen(input_command) > 0) && (input_command[strlen (input_command) - 1] == '\n'))
    {
        input_command[strlen (input_command) - 1] = '\0';
    }
    // input_command = ''
    //printf("\nInput_command: %c\n",input_command);

    /* Ask user for command. */
    printf("Type command you want to execute: ");
    
    // get data from stdin buffer and move to input_command
    fgets(input_command, 256 , stdin);
    // input_command = input from user    Ex: input_command = 'ls\n'  if type 'ls'
    //printf("\nInput_command: %s\n",input_command);
    
    /* Remove trailing newline, if there. */
    if ((strlen(input_command) > 0) && (input_command[strlen (input_command) - 1] == '\n'))
    {
        input_command[strlen (input_command) - 1] = '\0';
    }
    //input_command = ls // removed:'\n'

    /* Excute command on system*/
    system(input_command); 
    //system('ls')

    /* Free memory and exit. */
    free (input_command);
    printf("\n");

    // notice command executed
    printf("Command executed! \nType 'c' to continue, random to back: ");

    // stdin = '1'
    scanf("%c",main_mode);
    // stdin = c+'\n'
    // check condition to continue or break
    if(*main_mode=='c')
    {
        execute_command(main_mode);
    }        
}