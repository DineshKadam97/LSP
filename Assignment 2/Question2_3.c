///////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and print all
//                     file names from that directory.
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>


int main(int argc, char *argv[])
{
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
    
    printf("-------------------------------------------------\n");
    printf("Files From the directory %s are : \n", argv[1]);
    printf("-------------------------------------------------\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }
    printf("-------------------------------------------------\n");
    
    closedir(dp);

    return 0;
}
