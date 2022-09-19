#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[8] ={0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88};
	
	char* c1 = (char*)&c;
	printf("%x \n", *(c1+1));

    short int* c2 = (short int*)&c;
	printf("%hi \n", *(c2)); // decimal : 513
	
    int* c3 = (int*)&c;

	printf("%d \n", *(c3));
	
	double* c4 = (double*)&c;
	printf("%lf \n", *(c4));
	
	printf("size of char pointer %ld \n",sizeof(char*));
	printf("size of int pointer %ld \n", sizeof(int*));
	printf("size of double pointer %lu \n", sizeof(double*));
    printf("%lu",sizeof(double));

	return 0;
}
