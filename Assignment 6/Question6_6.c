///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and create hole in file if size 
//                     is less than 1kb and if its is greater than 1kb then truncate the file.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    char Arr[25];
    char Brr[25];
    char FileName[25];

    DIR *dp = NULL;
    struct dirent * entry = NULL;

    struct stat sobj;

    printf("PLease, enter the name of the directory\n");
    scanf("%s",Arr);

    dp = opendir(Arr);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)))
    {
        sprintf(FileName,"%s/%s",Arr,entry->d_name);

        stat(FileName,&sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > 1000)
            {
                truncate(FileName,1000);
            }
        }
    }
    
    return 0;
}
