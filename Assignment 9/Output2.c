#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int CountCapital(int fd)
{
    int iCnt = 0;
    int iCount = 0;
    int iRet = 0;
        
    char Buffer[BLOCKSIZE];      

    while((iRet = read(fd, Buffer, BLOCKSIZE)) != 0)
    {
        for(iCnt = 0; iCnt < iRet; iCnt++)
        {
            if((Buffer[iCnt] >= 'A') && (Buffer[iCnt] <= 'Z'))
            {
              iCount++;
            }
        }       
    }

    return iCount;
}

int main()
{
    int fd = 0;
    int iRet = 0;
    char Buffer[100] = {'\0'};

    printf("Inside Process1, PID of Parent process is  %d\n",getppid());

    fd = open("Demo.txt",O_RDONLY);

    iRet =  CountCapital(fd);
    printf("Number of capital letters  in Demo.txt are : %d\n", iRet);

    fd = open("Count.txt", O_RDWR | O_APPEND);
    if(fd == -1)
    {
        printf("unable to open Count.txt\n");
    }

    sprintf(Buffer, "Number of capital letters  in Demo.txt are : %d\n", iRet);

    write(fd, Buffer, strlen(Buffer));

    printf("Data has been written succesfully in Count.txt\n");

    return 0;
}