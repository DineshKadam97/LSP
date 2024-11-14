#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
  int fd = 0, iRet = 0;
  int iCount = 0;
  char Buffer[1024];
  
  fd = open("Demo.txt",O_RDONLY);
  if(fd == -1)
  {
    perror("Can not open file\n");
    return -1;
  }
  
  while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
  {
    for(int i = 0; i < iRet; i++)
    {
      if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
      {
        iCount++;
      }
    }
    memset(Buffer,0,sizeof(Buffer));
  }
  
  printf("Number of small letters are : %d\n",iCount);
  close(fd);
  return 0;
}
