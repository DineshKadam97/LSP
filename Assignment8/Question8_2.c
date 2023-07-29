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

    iRet1 = fork();
    if(iRet1 == 0)
    {
        execl("./Process2", "NULL", NULL);
    }
    else
    {
        printf("Process1 is the parent of Process2 and its PID is : %d\n", getpid());
    }

    return 0;
}