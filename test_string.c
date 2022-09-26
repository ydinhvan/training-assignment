/* scanf example */
#include <stdio.h>
#include<stdlib.h>
// void inline get()
// {
//   int c;
//   while ((c = getchar()) != '\n' && c != EOF);
// }

int main ()
{
  char str [80];
  int i;

  char *s = NULL;
  // %m: malloc memory
  // [^\n]: skip \n
  // %*c
  scanf("%m[^\n]%*c",&s);
  if (s) {
    printf("%s\n",s);
    free(s);
  }
  
  return 0;
}
