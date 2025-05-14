#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* Thread_Proc(void* ptr)
{
    int iNo = *(int*)ptr;
    printf("Inside Thread: Received Value = %d\n", iNo);

    // Allocate memory on heap to safely return result
    int* result = (int*)malloc(sizeof(int));
    if (result == NULL) {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }

    *result = iNo + 1; // Perform operation
    pthread_exit(result); // Return pointer to result
}

int main()
{
    int iret = 0;
    int iNo = 10;
    int *iValue = NULL;

    pthread_t TID;

    iret = pthread_create(&TID, NULL, Thread_Proc, &iNo);
    if (iret != 0) {
        perror("Failed to create thread");
        return 1;
    }

    printf("Thread Created successfully with TID: %ld\n", TID);

    // Correct way: pass address of iValue
    pthread_join(TID, (void **)&iValue);

    if (iValue != NULL) {
        printf("New Value is: %d\n", *iValue);
        free(iValue); // Free allocated memory
    } else {
        printf("Thread did not return any value.\n");
    }

    printf("End of main thread\n");
    pthread_exit(NULL); // Optional: exits main thread
    return 0;
}
