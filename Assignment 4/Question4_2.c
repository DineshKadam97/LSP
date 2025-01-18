/////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept directory name from user and create 
//                     new directory of that name.
//
///////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int iRet = 0;
    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }

    iRet = mkdir(argv[1], 0777);
    if(iRet == 0)
    {
        printf("Directory is created succesfully\n");
        return -1;
    }
    else
    {
        printf("Unable to create directory\n");
    }

    return 0;
}
