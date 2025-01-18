/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and combine all contents of 
//                     regular file from that directory into one file named as AllCombine.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    char FileName[256];
    char Buffer[BLOCKSIZE];

    struct stat sobj;
    
    int fdSource = 0;
    int fdDest = 0;
    int iRet = 0;

    DIR *dp = NULL;

    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fdDest = creat("AllCombine.txt", 0777);

    dp = opendir(argv[1]);

    if(dp == NULL)
    {
       printf("Unable to open the directory\n");
       return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
        sprintf(FileName, "%s/%s", argv[1], entry->d_name);
        
        stat(FileName, &sobj);
        if(S_ISREG(sobj.st_mode))
        {
           fdSource = open(FileName, O_RDONLY);

          while((iRet = read(fdSource, Buffer, sizeof(Buffer))) != 0)
          {
            write(fdDest, Buffer, iRet);
          }     
        }      
    }

    printf("%d", iRet);
    
    closedir(dp);
    
    return 0;
}
