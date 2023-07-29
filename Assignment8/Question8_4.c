////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program in which creates 2 processes as Process2 and Process3 and our parent
//                     process terminates till both the processes terminates.
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
    int cpid = 0;
    int Exit_Status = 0;

    iRet1 = fork();
    if(iRet1 == 0)
    {
        execl("./Process_2", "NULL", NULL);
    }
    else
    {
        printf("Process is waiting for child Process2 and its PID is : %d\n", getpid());
        cpid = wait(&Exit_Status);
        printf("Process2 has been terminated with PID %d and Exit Status %d\n", cpid, Exit_Status);
        
        iRet2 = fork();
        if(iRet2 == 0)
        {
            execl("./Process3", "NULL", NULL);
        }
        else 
        {
            printf("Process is the waiting for child Process3 and its PID is : %d\n",getpid());
            cpid = wait(&Exit_Status);
            printf("Process3 has been terminated with PID %d and Exit Status %d\n", cpid, Exit_Status);
        }
    }

    return 0;
}

