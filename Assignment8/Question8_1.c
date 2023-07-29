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
    int cpid = 0;
    int Exit_Status = 0;

    iRet = fork();
    if(iRet == 0)
    {
        execl("./ChildProcess","NULL",NULL);
    }
    else
    {
        printf("Parent process is waiting with ID : %d\n",getpid());
        cpid = wait(&Exit_Status);
        printf("Child process has terminated with PID %d and Exit Status %d\n", cpid, Exit_Status);
    }

    return 0;
}
