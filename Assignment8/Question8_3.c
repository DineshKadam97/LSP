////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program in which create 3 level process heirarchy where process1 creates
//                     process2 and it internally creates process3.
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
        printf("Process2 is created with process ID : %d\n",getpid());
    }
    else
    {
        printf("Process is the parent of Process2 and its PID is : %d\n", getpid());
        iRet2 = fork();
        if(iRet2 == 0)
        {
            printf("Process3 is created with PID : %d\n",getpid());
        }
        else 
        {
            printf("Process is the parent of Process3 and its PID is : %d\n",getpid());
            iRet3 = fork();
            if(iRet3 == 0)
            {
                printf("Process4 is created with PID : %d\n",getpid());
            }
            else
            {
                printf("Process is the parent of Process4 and its PID is : %d\n",getpid());
            }
        }
    }

    return 0;
}