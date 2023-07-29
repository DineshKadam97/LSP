////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which create 2 processes. Process 1 count number of capital letters
//                     from Demo.txt file. And process 2 count number of capital letters Hello.txt file.
//                     Both the processes write its count in Count.txt file.      
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int iRet1 = 0;
    int iRet2 = 0;

    iRet1 = fork();

    if(iRet1 == 0)
    {
       execl("./Process1", "NULL", NULL);     
    }
    else
    {
        printf("Parent process is running with process ID : %d\n",getpid());
        iRet2 = fork();
        if(iRet2 == 0)
        {
            execl("./Process2", "NULL", NULL);
        }
        else
        {
            printf("Parent process is running with process ID : %d\n",getpid());
        }
    }
    
    return 0;
}