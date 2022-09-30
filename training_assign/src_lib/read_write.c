#include "header_lib.h"

void lib_read_write()
{
    //system("cd /home/vany/Desktop/work/myproject/training_assign/test");
    /* Ask user for file. */
    printf("Type file you want to open\n");
    // malloc memory to save data from stdin
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
    
    // declare a file
    FILE* ptr;
    ptr = fopen(file_name, "a+");
    // Option a+: Open for update, append to end of file. If there no, creat new file
 
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
            // printf("Command executed! Type 'c' to continue, random to back: ");
            // mode = '\0';
            // scanf("%c",&mode);
            // scanf("%c",&mode);
            // if(mode=='c')
            // {
            //     lib_read_write();
            // }

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
            if(strlen(input_command) > 256)
            {
                printf("String two long, just get 256 character");
            }
            fprintf(ptr,"%s",input_command);
            free (input_command);
        }
        else 
        {
            printf("Type error -> Please type again!\n");
        }
    }
    free (file_name);
    // Closing the file
    fclose(ptr);
}