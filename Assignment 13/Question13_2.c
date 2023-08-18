//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates child process and parent process will communicate with child
//                     process by sending signals.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h> 

void sighup();
void sigint();
void sigquit();

int main()
{
    int pid = 0;
    if((pid = fork()) < 0)
    {
        exit(1);
    }

    if(pid == 0)
    {
        signal(SIGHUP,sighup);
        signal(SIGINT,sigint);
        signal(SIGQUIT,sigquit);
        for(;;);
    }
    else
    {
        printf("\nPARENT : Sending SIGHUP\n\n");
        kill(pid,SIGHUP);
        sleep(3);

        printf("\nPARENT : Sending SIGINT\n\n");
        kill(pid,SIGINT);
        sleep(3);

        printf("\nPARENT : Sending SIGQUIT\n\n");
        kill(pid,SIGQUIT);
        sleep(3);
    }
}

void sighup()
{
    signal(SIGHUP,sighup);
    printf("CHILD : I have received a SIGHUP\n");
}

void sigint()
{
    signal(SIGINT,sigint);
    printf("CHILD : I have received a SIGINT\n");
}

void sigquit()
{
    signal(SIGQUIT,sigquit);
    printf("CHILD : I have received a SIGQUIT\n");
    exit(0);
}
