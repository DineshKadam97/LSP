///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is used to create 2 threads by using appropriate synchronisation 
//                     technique to avoid the schduling problem.
//                     
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void * ptr)
{
    pthread_mutex_t *mutex = (pthread_mutex_t *)ptr;

    pthread_mutex_lock(mutex);
    int iCnt = 0;
    
    static int iCount = 0;
    iCount++;

    printf("Inside Thread %d\n", iCount);
    
    printf("Numbers in Ascending order are : \n");
    for(iCnt = 1; iCnt <= 100; iCnt++)
    {
        printf("%d\n", iCnt);
    }
    
    printf("Numbers in Descending order are : \n");
    for(iCnt = 100; iCnt >= 1; iCnt--)
    {
        printf("%d\n", iCnt);
    }

    pthread_mutex_unlock(mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_mutex_t mutex;
    int iCnt = 0;
    int mRet = 0;

    mRet = pthread_mutex_init(&mutex, NULL);

    if(mRet != 0)
    {
       printf("Init operation failed\n");
       return -1;
    }

    pthread_t TID[4];
   
    int iRet[4];

    for(iCnt = 0; iCnt < 4; iCnt++)
    {
        iRet[iCnt] = pthread_create(&TID[iCnt],
                                    NULL,
                                    Thread_Proc,
                                    &mutex);
    
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

        pthread_mutex_destroy(&mutex);
    

    printf("End of main thread\n");
    
    return 0;
}