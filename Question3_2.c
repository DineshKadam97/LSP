///////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name and file name from user 
//                     and check whether that file is present in the directory or not.
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    char FileName[255];
    DIR *dp = NULL;

    struct dirent *entry = NULL;

    if(argc != 3)
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
        if(strcmp(entry->d_name, argv[2]) == 0)
        {
            break;
        }
    }
    
    if(entry == NULL)
    {
      printf("%s is not present in the directory %s\n", argv[2], argv[1]);
    }
    else
    {
      printf("%s is present in the directory %s\n", argv[2], argv[1]);
    }
    
    closedir(dp);
    
    return 0;
}
