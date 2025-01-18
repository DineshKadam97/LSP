//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and print name of
//                     such file which has the largest size.
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int iMax = 0;
    struct stat sobj;
    char FileName[25];
    char LargestFile[30];

    DIR *dp = NULL;

    struct dirent *entry = NULL;

    if(argc != 2)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }

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
          if(sobj.st_size > iMax)
          {
            iMax = sobj.st_size;
            strcpy(LargestFile, entry->d_name);
          }
        }
    }
   
    printf("Largest file is : %s, with size %d bytes\n", LargestFile, iMax);
    
    closedir(dp);
   
    return 0;
}
