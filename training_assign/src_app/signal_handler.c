#include "header_app.h"

// Signal Handler for SIGINT 
void sigintHandler(int sig_num)
{
    printf("\nDo you want to close? yes(y) or no(n): ");
    char* quit=NULL;
    scanf("%m[^\n]%*c",&quit);
    if (*quit =='y')
    {
        //status = false;
        // free memory after malloc
        free(quit);
        // return 0 to the parent process
        exit(0);
    }
    else
    {
        sigintHandler(SIGINT);
    }
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