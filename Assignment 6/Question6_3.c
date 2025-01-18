////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name and file name from user and create 
//                     that file in the directory.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>


int main()
{
    int iRet = 0;
    int fd = 0;
    struct stat sobj;
    char Arr[25];
    char Brr[25];
    char FileName[25];

    printf("PLease, enter the name of the directory\n");
    scanf("%s",Arr);

    printf("Please, enter the name of the file\n");
    scanf(" %s",Brr);

    sprintf(FileName,"%s/%s",Arr,Brr);

    fd = creat(FileName, 0777);
    if(fd == 0)
    {
        printf("Unable to creat file\n");
        return -1;
    }

    close(fd);
    
    return 0;
}
