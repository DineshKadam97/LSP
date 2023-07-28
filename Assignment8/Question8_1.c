////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program in which parent process wait till its child process
//                     terminates.
//
///////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    int iRet = 0;

    iRet = fork();
    if(iRet == 0)
    {
        printf("Child process is running with process ID : %d\n",getpid());
    }
    else
    {
        printf("Parent process is waiting with ID : %d\n",getppid());
        wait(NULL);
        printf("Child process has terminated\n");
    }

    return 0;
}
