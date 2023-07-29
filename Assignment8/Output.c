#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside Child Process, PID of Parent process is  %d\n",getppid());

    return 0;
}