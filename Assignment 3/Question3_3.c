////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept 2 directory names from user and move all
//                     files from sorce diretory to destination directory.
//
///////////////////////////////////////////////////////////////////////////////////////////////

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
    
    struct stat sobj;

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
        rename(argv[1], argv[2]);
    }
    
    closedir(dp);
    
    return 0;
}
