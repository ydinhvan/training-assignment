#include<stdio.h>
#include"TutorialConfig.h"
#include<stdlib.h>
#include<math.h>

#ifdef USE_MYMATH
#  include "MathFunctions.h"
#endif
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue sqrt(9);
#endif


int main(int argc, char** argv) 
{
    printf("Hello Bosch\n");
    if (argc < 2) 
    {
    // report version
    printf("Version %s %d.%d \n",argv[0],Tutorial_VERSION_MAJOR,Tutorial_VERSION_MINOR,"\n");
    printf("Usage:%s number\n",argv[0]);
    return 1;
    }
}