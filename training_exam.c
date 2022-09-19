#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h> 

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

    char main_mode;

    // intinial program
    intinial_func();
    
    //printf("%c\n",main_mode);
    while(status==true)
    {
        //Type input
        scanf("%c",&main_mode);
        if (main_mode == '1')
        {
            execute_command(&main_mode);
            main_mode = '\0';
            intinial_func();
        }
        else if (main_mode == '2')
        {
            lib_read_write(&main_mode);
            main_mode = '\0';
            intinial_func();
        }
        else 
        {
            printf("Type error -> Please type again!\n");
            //scanf("%c",&main_mode);
        }
    }
    return 0;
}

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

// Signal Handler for SIGINT 
void sigintHandler(int sig_num)
{
    // Reset handler to catch SIGINT next time.
    // Refer http://en.cppreference.com/w/c/program/signal
    // signal(SIGINT, sigintHandler);
    // printf("\n Cannot be terminated using Ctrl+C \n");
    printf("\nDo you want to close? yes(y) or no(n): ");
    char quit;
    scanf("%c",&quit);
    if (quit =='y')
    {
        status = false;
    }
}

void execute_command(char* main_mode)
{
    //char input_command;
    //scanf("%c",&input_command);
    //check if command processor is available in the operating system or not
    //if(system(NULL))
    //{

        /* Ask user for command. */
        printf("Type command you want to execute: ");

        char *input_command = (char*)malloc(256);
        if (input_command == NULL)
        {
            printf("No memory\n");
            return;
        }
      
        /* Get the name, with size limit. */
        
        fgets(input_command, 256 , stdin);
        //gets(input_command);

        printf("%s",input_command);
        /* Remove trailing newline, if there. */
        if ((strlen(input_command) > 0) && (input_command[strlen (input_command) - 1] == '\n'))
        {
            input_command[strlen (input_command) - 1] = '\0';
        }

        //char input_command[20];
        //scanf("%20[^\n]", input_command);
        fgets(input_command, 256 , stdin);
        /* Excute command */
        system(input_command);
    
        /* Free memory and exit. */
        free (input_command);
        
        printf("\n");
        printf("Command executed! Type 'c' to continue, random to back: ");

        scanf("%c",main_mode);

        if(*main_mode=='c')
        {
            execute_command(main_mode);
        }
        
    // }
    // else
    // {
    //    printf("Command processor is not present \n");
    // }
}

void lib_read_write(char* main_mode)
{
    /* Ask user for command. */
    printf("Type file you want to open\n ");
    
    char *file_name = (char*)malloc(256);
    if (file_name == NULL)
    {
        printf("No memory\n");
        return;
    }
    /* Get the name, with size limit. */
    
    fgets(file_name, 256 , stdin);
    //gets(input_command);

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
    ptr = fopen(file_name, "r+");
 
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
            char ch;
            printf("content of this file are \n");
            // Printing what is written in file
            // character by character using loop.
            do {
                ch = fgetc(ptr);
                printf("%c", ch);
        
                // Checking if character is not EOF.
                // If it is EOF stop eading.
            } while (ch != EOF);
        }
        else if (mode == 'w')
        {
            char string[100];
            printf("Type whatever you want\n");
            fgets(string, 100, stdin);
        }
        else 
        {
            printf("Type error -> Please type again!\n");
        }
    }
        
    // Closing the file
    fclose(ptr);
}
