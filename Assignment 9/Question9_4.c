/////////////////////////////////////////////////////////////////////////////////////////////
//
//  Problem Statement : Write  a program to increase the priority of process by 5
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    
    iRet = getpriority(PRIO_PROCESS, 0);
    printf("Default priority of the process is : %d\n", iRet);

  
    iRet = nice(-5);

    printf("Modified Priority of the process is %d\n", iRet);

    return 0;
}
