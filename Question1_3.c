////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which accept file name and mode from user and check 
//                     whether our process can access that file or not.
//
//////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int iRet = 0;
    int mode = 0;

    if(argc != 3)
    {
        printf("Invalid number of arguments\n");
        return -1;
    }
    
    if((strcmp(argv[2], "read") == 0))
    {
      mode = R_OK;
    }
    if((strcmp(argv[2], "write") == 0))
    {
      mode = W_OK;
    }
    if((strcmp(argv[2], "execute") == 0))
    {
      mode = X_OK;
    }
    
    iRet = access(argv[1], mode);
    if(iRet == 0)
    {
       printf("Our program can access the file in the given mode\n");
    }
    else
    {
       printf("Our program can not access the file in the given mode\n");
    }

    return 0;
}
