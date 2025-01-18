//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which creates multiple threads and set its thread attributes 
//                     accordingly.
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void * ptr)
{
    int A = (int)ptr;
    printf("Inside Thread %d\n", A);

    pthread_exit(NULL);
}

int main()
{
    int iCnt = 0;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    size_t stack_size = 1024 * 1024;
    pthread_attr_setstacksize(&attr, stack_size);

    int policy = SCHED_FIFO;
    pthread_attr_setschedpolicy(&attr, policy);

    struct sched_param param;

    param.sched_priority = 50;
    pthread_attr_setschedparam(&attr, &param);

    pthread_t TID[4];
    int iRet[4];

    for(iCnt = 0; iCnt < 4; iCnt++)
    {
        iRet[iCnt] = pthread_create(&TID[iCnt],
                                    &attr,
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

    pthread_attr_destroy(&attr);

    printf("End of main thread\n");
    
    return 0;
}