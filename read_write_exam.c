// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Driver code
int main()
{
    FILE* ptr;
    char ch;
    char file_name[] = "test.txt";
    ptr = fopen(file_name, "a+");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    printf("content of this file are: \n");
    
    while (!feof(ptr)) {
        ch = fgetc(ptr);
        printf("%c", ch);
    }
    printf("\nIn writing mode, type what ever you want: ");
    char *input_command = (char*)malloc(256);
    /* Get the name, with size limit. */
    
    fgets(input_command, 256 , stdin);

    /* Remove trailing newline, if there. */
    if ((strlen(input_command) > 0) && (input_command[strlen (input_command) - 1] == '\n'))
    {
        input_command[strlen (input_command) - 1] = '\0';
    }

    //fgets(input_command, 256 , stdin);
    fprintf(ptr,"%s",input_command);

    free (input_command);
    fclose(ptr);
    return 0;
}
