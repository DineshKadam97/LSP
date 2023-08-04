//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is used to create 2 threads using pthread library, first thread
//                     prints number from 1 to 500 and second thread prints number from 500 to 1
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<pthread.h>

void * Ascending(void * ptr)
{
    int iCnt = 0;

    printf("Inside Thread1\n");

    for(iCnt = 1; iCnt <= 500; iCnt++)
    {
        printf("%d\n", iCnt);
    }

    pthread_exit(0);
}

void * Descending(void * ptr)
{
    int iCnt = 0;

    printf("Inside Thread2\n");

    for(iCnt = 500; iCnt >= 1; iCnt--)
    {
        printf("%d\n", iCnt);
    }

    pthread_exit(0);
}

int main()
{
    int iRet1 = 0, iRet2 = 0;

    pthread_t TID1;

    iRet1 = pthread_create(&TID1,
                          NULL,
                          Ascending,
                          NULL);
    
    if(iRet1 != 0)
    {
        printf("Unable to create thread1\n");
        return -1;
    }

    printf("Thread1 is created succesfully with ID : %ld\n", TID1);

    pthread_t TID2;

    iRet2 = pthread_create(&TID2,
                          NULL,
                          Descending,
                          NULL);
    
    if(iRet2 != 0)
    {
        printf("Unable to create thread2\n");
        return -1;
    }

    printf("Thread2 is created succesfully with ID : %ld\n", TID2);

    pthread_join(TID1, NULL);
    pthread_join(TID2, NULL);
    
    return 0;
}