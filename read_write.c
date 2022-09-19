#include <lib_training_exam.h>
#include <stdio.h>

// function to read
void lib_read_write(char file[])
{
    FILE* ptr;
    char ch;
    char mode;
    // Opening file in reading mode
    ptr = fopen(file, "w+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
    printf("Do you want to read or write file ? \n");
    printf("Type 'r' to read\n");
    printf("Type 'w' to write\n");
    scanf("%c",&mode);
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
        printf("Type whatever you want");
        scanf("%s", string);
    }
        
    // Closing the file
    fclose(ptr);
}