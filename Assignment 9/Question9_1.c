////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates new process which is responsible to write all file names
//                     which are prsent on Desktop in demo file which should be created newly.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    }

    return 0;
}
