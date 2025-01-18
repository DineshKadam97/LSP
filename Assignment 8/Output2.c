#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    printf("Inside Process2, PID of Parent process is  %d\n",getppid());

    iRet = fork();
    if(iRet == 0)
    {
        execl("./Process3", "NULL", NULL);
    }
    else
    {
        printf("Process2 is the parent process of Procees3 and running with PID %d\n", getpid());
    }

    return 0;
}