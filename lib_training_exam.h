#ifndef LIB_TRAINING_EXAM
#define LIB_TRAINING_EXAM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

// declare function
void declare(char mode)
{
    printf("Application has 2 mode: Read/Write and execute a command\n");
    printf("Type to choice mode:\n");
    printf("Type '1' to choice read/write mode\n");
    printf("Type '2' to choice read/write mode\n");
    // Type input
    scanf("%i",mode);
    return mode;
}

// library can read and write text to a file
void lib_read_write()
{
    FILE* ptr;
    char ch;
    char mode;
    char file_name;

    printf("Type file you want to open\n");
    // Opening file in reading and writing mode
    ptr = fopen(scanf(&file_name), "w+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    else 
    {
        printf("Do you want to read or write file ? \n");
        printf("Type 'r' to read\n");
        printf("Type 'w' to write\n");
        scanf("%i",&mode);
        
        if(mode == 'r')
        {
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
            char string;
            printf("Type whatever you want\n");
            scanf("%i", &string);
        }
    }
        
    // Closing the file
    fclose(ptr);
}

void execute_command()
{

    //check if command processor is available in the operating system or not
    //if(system(NULL))
    //{
        char main;
        scanf("%c",&main);
        char *input_command = (char*)malloc(256);
        if (input_command == NULL)
        {
            printf("No memory\n");
            return;
        }
        /* Ask user for command. */
        printf("Type command: \n");

        /* Get the name, with size limit. */
        
        fgets(input_command, 256 , stdin);
        //gets(input_command);

        /* Remove trailing newline, if there. */
        if ((strlen(input_command) > 0) && (input_command[strlen (input_command) - 1] == '\n'))
        {
            input_command[strlen (input_command) - 1] = '\0';
        }

        /* Excute command */
        system(input_command);
    
        /* Free memory and exit. */
        free (input_command);
        

        //char name[20];

        // get up to buffer size - 1 characters (to account for NULL terminator)
        //scanf("%19[^\n]", name);
    //}
    //else
    //{
    //    printf("Command processor is not present \n");
    //}
}

#endif