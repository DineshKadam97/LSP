//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates such a process which accept signals from terminal.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int iRet = 0;
  int cpid = 0;
  int EXIT_STATUS = 0;

  iRet = fork();
  if(iRet == 0)
  {
    execl("./ChildProcess","NULL",NULL);
  }
  else
  {
    cpid = wait(&EXIT_STATUS);
    printf("Parent process created the ChildProcess\n");
  }

  return 0;
}