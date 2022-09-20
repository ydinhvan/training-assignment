#include<string.h>
#include<stdlib.h>
#include<stdio.h>

char string_upper (char* str);
char string_lower (char* str);

void main()
{
    int word=0, space = 0;
    char temp_name[10][10];
    // Declare input name
    char* input_name;
    input_name = (char*)malloc(100);
    // check if input name point to NULL
    if (input_name == NULL)
        {
            printf("No memory\n");
            return;
        }  
    /* Get the name, with size limit. */
    fgets(input_name, 100, stdin);
    /* Remove trailing newline, if there. */
    if ((strlen(input_name) > 0) && (input_name[strlen (input_name) - 1] == '\n'))
    {
        input_name[strlen (input_name) - 1] = '\0';
    }

    // print input
    printf("Input:");
    for (int i=0;i<strlen(input_name);i++)
    {
        char ch = input_name[i];
        if( ch ==' ')
        {
            ch ='_';
        }
        printf("%c",ch);
    }
    printf("\n");

    // Main algorithm
    int j = 0, count = 0;
    for(int i=0; i < strlen(input_name); i++)
    {
        if (input_name[i] != ' ')
        {
            j=i;
            while (input_name[j] != ' ')
            {
               //printf("\ninput_name[%d] = %c   ",j, input_name[j]);
               temp_name[word][count] = string_lower(&input_name[j]);
               //printf("temp_name[%d][%d] = %c\n",word, count, temp_name[word][count]);
               count = count + 1; 
               j = j+1;
               if (j == strlen(input_name))
               {
                    break;
               }
            }
            //printf("\n");
            word = word + 1;
            i = j;
            count =0;
        }
    }       

    printf("Output:");
    for (int i=0;i<word;i++)
    {
        temp_name[i][0] = string_upper(&temp_name[i][0]);
        printf("%c",temp_name[i][0]);
        j = 1;
        while (temp_name[i][j] != '\0')
        {
            printf("%c",temp_name[i][j]);
            j = j+1;
        }
        if (i != word-1)
        {
            printf("%c",'_');
        }
    }

    // print total word
    printf("\nWord: %d\n",word);
    // print length of string 
    printf("Length of string name: %ld\n",strlen(input_name));
    // free memory of input_name
    free(input_name);

}

// Upper tring
char string_upper (char* str) {
    if(*str >= 97 && *str <= 122)
        *str = *str - 32;
        return *str;
}

// Lower string
char string_lower(char* str) {
    if(*str >= 65 && *str <= 90)
        *str = *str + 32;
    return *str;
}