/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

char *solution(int N, int K) 
{
    char *result = (char*) malloc(N * sizeof(char));
    //char result[N];
    int mean_div = N / 2;
    if (N>200 || N<0 || K>26 || K<1) 
    {
        printf("type input false");
        return 0;
    }
    else
    {
        if (K == 1) 
        {
            for (int i=0;i<N;i++)
            {
                result[i]=97;
            }    
        }
        else if ((N%2)==1)
        {
            int x = N/2;
            x = x+1;
            if (K<=x)
            {
                result[mean_div] = (K + 96);
                K = K-1;
                for (int i = 0; i < mean_div; i++ )
                {
                    result[i] = (96+K);
                    result[N-i-1] = (96+K);
                    K = K-1;
                    if (K == 0) 
                    {
                        K=1;
                    }
                }
            }
            else 
            {
                printf("type input false");
                return 0;
            }
        }
        else
        {
            int x = N/2;
            if (K<=x)
            {
                for (int i = 0; i < mean_div; i++ )
                {
                    result[i] = (96+K);
                    result[N-1-i] = (96+K);
                    K = K-1;
                    if (K == 0)
                    {
                        K=1;
                    }
                }
            }
            else 
            {
                printf("type input false");
                return 0;
            }
            
        }
    }
    
    return result;
}

int main()
{
    int n ;
    int k ;
    scanf("%d",&n);
    scanf("%d",&k);
    //write your code in C99 (gcc 6.2.0)
    
    printf("%d \n",n);
    printf("%d \n",k);
    
    char *str = solution(n, k);
    printf("%s \n",str);
    free(str);
    //int *a = (int*)malloc(5*sizeof(int));
    //free(a);
    return 0;
}
