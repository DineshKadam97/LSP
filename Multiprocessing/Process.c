#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
  int iRet1 = 0, iRet2 = 0, EXIT_STATUS;
  
  iRet1 = fork();
  
  if(iRet1 == 0)
  {
    execl("./Capital", "NULL", NULL);
  }
    wait(&EXIT_STATUS);
  
  iRet2 = fork();
  
  if(iRet2 == 0)
  {
    execl("./Small", "NULL", NULL);
  }
  wait(&EXIT_STATUS);
  return 0;
}
