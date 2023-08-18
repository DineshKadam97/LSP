////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates two processes as sender and receiver in which sender process
//                     send signal to receiver process.
//                     
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>

void sighup();
void sigint();
void sigquit();

int main()
{
  int pidSender = 0;
  int pidReceiver = 0;
  int cpid = 0;
  int EXIT_STATUS = 0;

  if((pidReceiver = fork()) < 0)
  {
    exit(1);
  }

  if(pidReceiver == 0)
  {
    signal(SIGHUP,sighup);
    signal(SIGINT,sigint);
    signal(SIGQUIT,sigquit);
    for(;;);
  }
  else
  {
    printf("Parent process created the Receiver process\n");

    if((pidSender = fork()) < 0)
    {
      exit(1);
    }

    if(pidSender == 0)
    {
      printf("\nSENDER : Sending SIGHUP\n\n");
      kill(pidReceiver,SIGHUP);
      sleep(3);

      printf("\nSENDER : Sending SIGINT\n\n");
      kill(pidReceiver,SIGINT);
      sleep(3);

      printf("\nSENDER : Sending SIGQUIT\n\n");
      kill(pidReceiver,SIGQUIT);
      sleep(3);
    }
    else
    {
      printf("Parent process created the Sender Process\n");
    }

    cpid = wait(&EXIT_STATUS);
  }
}

void sighup()
{
    signal(SIGHUP,sighup);
    printf("RECEIVER : I have received a SIGHUP\n");
}

void sigint()
{
    signal(SIGINT,sigint);
    printf("RECEIVER : I have received a SIGINT\n");
}

void sigquit()
{
    signal(SIGQUIT,sigquit);
    printf("RECEIVER : I have received a SIGQUIT\n");
    exit(0);
}