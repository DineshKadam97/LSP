//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is used to create 4 threads and our main thread waits till 
//                     all threads terminates.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void * ptr)
{
    printf("Inside Thread %d\n",(int*)ptr);

    pthread_exit(NULL);
}

int main()
{
    int iCnt = 0;

    pthread_t TID[4];
    int iRet[4];

    for(iCnt = 0; iCnt < 4; iCnt++)
    {
        iRet[iCnt] = pthread_create(&TID[iCnt],
                                    NULL,
                                    Thread_Proc,
                                    (int *)(iCnt+1));
    
       if(iRet[iCnt] != 0)
       {
        printf("Unable to create thread\n");
        return -1;
       }

       printf("Thread%d is created succesfully with ID : %ld\n", iCnt+1, TID[iCnt]);
    }

    for(iCnt = 0; iCnt < 4; iCnt++)
    {
        pthread_join(TID[iCnt], NULL);
    }

    printf("End of main thread\n");
    
    return 0;
}
