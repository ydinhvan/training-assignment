#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h> 
//#include "lib_training_exam.h"


bool status = true;

void sigintHandler(int sig_num);
void execute_command();
void lib_read_write();
void intinial_func();


int main( int argc, char *argv[] )
{
    // ignore interrupt signal
    signal(SIGINT, sigintHandler);
    
    //clear console
    system("clear");

    // declare input variation
    char main_mode;

    // intinial program
    intinial_func();
    
    while(status==true)         // If Ctrl+C isn't pressed
    {
        //Type input mode
        scanf("%c",&main_mode);
        // Skip if main_mode ='\n'
        if (main_mode == '\n')
        {
            continue;
        }
        // print main_mode
        printf("%c\n",main_mode);
        if (main_mode == '1')
        {
            // mode 1: execute command
            execute_command(&main_mode);
            main_mode = '\0';
            intinial_func();
        }
        else if (main_mode == '2')
        {
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

// Signal Handler for SIGINT 
void sigintHandler(int sig_num)
{
    printf("\nDo you want to close? yes(y) or no(n): ");
    char quit;
    scanf("%c",&quit);
    if (quit =='y')
    {
        status = false;
    }
}

// Intinial function: print instructions
void intinial_func()
{
    printf("\nApplication has 2 mode: Read/Write and execute a command\n");
    printf("Type '1' to choice execute command mode\n");
    printf("Type '2' to choice read/write mode\n");
}

/*
// Block signal
void signal_block()
{
    declare a signal handle mask
    sigset_t my_sigset;
    
    empty signal mask
    sigemptyset(&my_sigset);
    
    set signal SIGINT to 1
    sigaddset(&my_sigset, SIGINT);

    Request to block signal SIGINT
    sigprocmask(SIG_BLOCK,&my_sigset,NULL);
    sigpending(&my_sigset); 
}
*/

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

void lib_read_write()
{
    /* Ask user for file. */
    printf("Type file you want to open\n");
    // malloc memory to save data
    char *file_name = (char*)malloc(256);
    // check if malloc to NULL memory
    if (file_name == NULL)
    {
        printf("No memory\n");
        return;
    }
    /* Get the name from stdin buffer, with size limit. */   
    fgets(file_name, 256 , stdin);
    /* Remove trailing newline, if there. */
    if ((strlen(file_name) > 0) && (file_name[strlen(file_name) - 1] == '\n'))
    {
        file_name[strlen(file_name) - 1] = '\0';
    }
    
    fgets(file_name, 256 , stdin);

    /* Remove trailing newline, if there. */
    if ((strlen(file_name) > 0) && (file_name[strlen(file_name) - 1] == '\n'))
    {
        file_name[strlen(file_name) - 1] = '\0';
    }
    
    FILE* ptr;
    ptr = fopen(file_name, "a+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    else 
    {
        printf("Do you want to read or write file ? \n");
        printf("Type 'r' to read\n");
        printf("Type 'w' to write\n");
        
        char mode;
        scanf("%c",&mode);
        
        if(mode == 'r')
        {
            char ch='\0';
            printf("content of this file are \n");
            // Printing what is written in file
            // character by character using loop.
            ch = fgetc(ptr);
            // Checking if character is not EOF.
            // If it is EOF stop eading.
            while (ch != EOF)
            {
                
                printf("%c", ch);
                ch = fgetc(ptr);
            } 
            printf("\n");
            printf("Command executed! Type 'c' to continue, random to back: ");
            mode = '\0';
            scanf("%c",&mode);
            scanf("%c",&mode);
            if(mode=='c')
            {
                lib_read_write();
            }

        }
        else if (mode == 'w')
        {
            printf("\nIn writing mode, type what ever you want: ");
            char *input_command = (char*)malloc(256);
            /* Get the name, with size limit. */
            
            fgets(input_command, 256 , stdin);

            /* Remove trailing newline, if there. */
            if ((strlen(input_command) > 0) && (input_command[strlen (input_command) - 1] == '\n'))
            {
                input_command[strlen (input_command) - 1] = '\0';
            }

            fgets(input_command, 256 , stdin);
            fprintf(ptr,"%s",input_command);
            free (input_command);
        }
        else 
        {
            printf("Type error -> Please type again!\n");
        }
    }
        
    // Closing the file
    fclose(ptr);
}