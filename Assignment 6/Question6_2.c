//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates hole of size 10kb at the end of the file.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

#pragma pack(1)

struct FileInfo
{
    char FName[20];
    char FSize;
};

int main(int argc, char *argv[])
{
    int iRet = 0;
    struct stat sobj;
    char FileName[256];

    struct FileInfo fobj;
    
    int fd = 0;
    
    fd = open(argv[1], O_RDONLY);
    
   while((iRet = read(fd, &fobj, sizeof(fobj))) !=0)
   {
     if(fobj.FSize > 10)
     {
       printf("%s\n", fobj.FName);
     }   
   }
    
    return 0;
}
