////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program in which create 3 different processes internally 3 different processes
//                     internally as Process2, Process3 and Process4.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
    int iRet1 = 0;
    int iRet2 = 0;
    int iRet3 = 0;

    iRet1 = fork();
    if(iRet1 == 0)
    {
        execl("./Process_2", "NULL", NULL);
    }
    else
    {
        printf("Process is the parent of Process2 and its PID is : %d\n", getpid());
        iRet2 = fork();
        if(iRet2 == 0)
        {
            execl("./Process3", "NULL", NULL);
        }
        else 
        {
            printf("Process is the parent of Process3 and its PID is : %d\n",getpid());
            iRet3 = fork();
            if(iRet3 == 0)
            {
                execl("./Process4", "NULL", NULL);
            }
            else
            {
                printf("Process is the parent of Process4 and its PID is : %d\n",getpid());
            }
        }
    }

    return 0;
}