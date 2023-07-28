#include<fcntl.h>
#include<unistd.h>
#include"FileCompare.h"
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>

bool FileCompare(char str1[], char str2[])
{   
    int Buffer1[1024];
    int Buffer2[1024];

    int iRet = 0;

    int fd1 = open(str1, O_RDONLY);
    int fd2 = open(str2, O_RDONLY);
    if((fd1 == -1) || (fd2 == -1))
    {
        printf("Unable to open file\n");
        return -1;
    }

    struct stat sobj1;
    struct stat sobj2;

    fstat(fd1, &sobj1);
    fstat(fd2, &sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are different as sizes are different\n");
        return -1;
    }

    while((iRet = read(fd1, Buffer1, sizeof(Buffer1))) != 0)
    {
      iRet = read(fd2, Buffer2, sizeof(Buffer2));

      if (memcmp(Buffer1, Buffer2, iRet) != 0)
      {
         break;
      }
    }
    
    if(iRet == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
}
