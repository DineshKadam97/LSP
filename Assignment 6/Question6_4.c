//////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and delete all such
//                     files whose size is greater than 100 bytes.
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
          if(sobj.st_size > 100)
          {
            remove(FileName);
          }
        }
    }
   
    printf("Files greater than 100 bytes are deleted succesfully\n");
    
    closedir(dp);
   
    return 0;
}
