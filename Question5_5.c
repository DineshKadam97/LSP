//////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name which contains data of all file. We 
//                     have to create all files again.
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
    int fd = 0;
    
    char FileName[256];

    struct FileInfo fobj;
    
    fd = open(argv[1], O_RDONLY);
    
   while((iRet = read(fd, &fobj, sizeof(fobj))) !=0)
   {
      creat(fobj.FName, 0777);
   }
    
    return 0;
}
