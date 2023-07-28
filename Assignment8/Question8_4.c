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
        printf("Process is waiting for child Process2 and its PID is : %d\n", getpid());
        wait(NULL);
        printf("Process2 has been terminated\n");
        
        iRet2 = fork();
        if(iRet2 == 0)
        {
            printf("Process3 is created with PID : %d\n",getpid());
        }
        else 
        {
            printf("Process is the waiting for child Process3 and its PID is : %d\n",getpid());
            wait(NULL);
            printf("Process3 has been terminated\n");
        }
    }

    return 0;
}

