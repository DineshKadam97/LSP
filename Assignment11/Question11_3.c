//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Problem Statement : Write a program which is used to predict the problem due to lack of synchronisation
//                     
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// As we dont used the synchronisatation technique in this code, so after creating the first thread, for loop from the function 
// Thread_Proc starts running but before the for loop ends second thread will get created and thread scheduler will schedule 
// that thread. So, at this point 2 threads Thread1 and Thread2 will run the for loop at the same time and we will get 
// the undesirable output, where sequence will not be followed properly as multiple threads are running the same function
// simultaneously. 
// But, if we use synchronisation technique like mutex, then we can avoid this problem. Because, if we use the mutex in 
// our code then only one thread will be running the particular function at a time.


#include<stdio.h>
#include<pthread.h>

void * Thread_Proc(void * ptr)
{
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
                                    NULL);
    
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
