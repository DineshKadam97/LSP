//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and write information of all 
//                     regular file in file and then read the contents from that file.
//
////////////////////////////////////////////////////////////////////////////////////////////////

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
    struct stat sobj;
    char FileName[256];

    struct FileInfo fobj;
    
    int fd = 0;

    DIR *dp = NULL;

    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

    fd = creat("FileCombine.txt", 0777);

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
            fobj.FSize = sobj.st_size;
            strcpy(fobj.FName, entry->d_name);
            write(fd, &fobj, sizeof(fobj));
            printf("%s\n");
            
            read(fd, &fobj, sizeof(fobj));
    
            printf("Name of the file is : %s\n", fobj.FName);
            printf("Size of the file is : %d\n\n", fobj.FSize);     
        }      
    }
    
    closedir(dp);
    
    return 0;
}
