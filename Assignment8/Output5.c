#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Inside Process_2, PID of Parent process is  %d\n",getppid());

    return 0;
}