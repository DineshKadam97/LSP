/////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept 2 file names from user and check whether
//                     contents of the two files are equal or not.
//
///////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = 0;
    int fd2 = 0;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];
    int iRet1 = 0;
    int iRet2 = 0;
    int iSize1 = 0;
    int iSize2 = 0;

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }
    
    struct stat sobj;

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fd2 = open(argv[2], O_RDONLY);
    if(fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }
    
    stat(argv[1], &sobj);  
    iSize1 = sobj.st_size;
    
    stat(argv[2], &sobj);
    iSize2 = sobj.st_size;
    
    if(iSize1 != iSize2)
    {
      printf("Contents of the file are not equal\n");
      return 0;
    }
    
    while((iRet1 = read(fd1, Buffer1, sizeof(Buffer1)) != 0) && (iRet1 = read(fd1, Buffer1, sizeof(Buffer1)) != 0))
    {
       if(memcmp(Buffer1, Buffer2, sizeof(Buffer1)) != 0)
       {
         break;
       }
    }
    
    if(iRet1 == 0) 
    {
      printf("Contents of the file are equal\n");
    }
    else
    {
      printf("Contents of the file are not equal\n");
    }
    
    
    return 0;
}
