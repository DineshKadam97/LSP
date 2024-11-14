#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

void* CountCapital(void* ptr)
{
  int fd = *(int*)ptr;
  int iRet = 0;
  char Buffer[BLOCKSIZE];
  int iCount = 0;
  
 lseek(fd, 0, SEEK_SET);
  
  while((iRet = read(fd,Buffer,BLOCKSIZE)) != 0)
  {
    for(int i = 0; i < iRet; i++)
    {
       if(Buffer[i] > 'A' && Buffer[i] < 'Z')
       {
         iCount++;
       }
    }
  }
  
  int* result = malloc(sizeof(int));
  *result = iCount;
  pthread_exit(result);
}

void* CountSmall(void* ptr)
{
  int fd = *(int*)ptr;
  int iRet = 0;
  char Buffer[BLOCKSIZE];
  int iCount = 0;
  
 lseek(fd, 0, SEEK_SET);
  
  while((iRet = read(fd,Buffer,BLOCKSIZE)) != 0)
  {
    for(int i = 0; i < iRet; i++)
    {
       if(Buffer[i] > 'a' && Buffer[i] < 'z')
       {
         iCount++;
       }
    }
  }
  
  int* result = malloc(sizeof(int));
  *result = iCount;
  pthread_exit(result);
}

int main()
{
  pthread_t TID1, TID2;
  int fd = 0;
  int* iValue = NULL;
                 
  fd = open("Demo.txt",O_RDONLY);
  if(fd == -1)
  {
    perror("Can not open file\n");
    return -1;
  }
  
    pthread_create(&TID1,
                   NULL,
                   CountCapital,
                   &fd);
                 
   pthread_create(&TID2,
                  NULL,
                 CountSmall,
                 &fd);
                 
  pthread_join(TID1,(void **)&iValue);
  printf("Capital letters : %u\n",*iValue);
  free(iValue);
  
  pthread_join(TID2,(void **)&iValue);
  printf("Small letters : %u\n",*iValue);
  free(iValue);
  
  close(fd);
  pthread_exit(NULL);
  
  return 0;
}
