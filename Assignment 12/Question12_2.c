//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is used to create two processes and that two processes can communicate
//                     with each other by using the concept of shared memory.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>   

#define BLOCKSIZE 1024

int main()
{
    int FD[2];
    int iRet = 0; 

    iRet = fork();

    if(iRet == 0)
    {
        execl("./ChildProcess1","NULL",NULL);
    }
    else
    {
        printf("Parent process created ChildProcess1");

        iRet = fork();
        if(iRet == 0)
        {
            execl("./ChildProcess2","NULL",NULL);
        }
        else
        {
            printf("Parent process created ChildProcess2");
        }
    }
   
    return 0;
}
