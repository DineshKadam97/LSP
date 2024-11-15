#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

// void * _____ (void * ___)
// {}

void * ThreadProc(void *ptr)
{
  printf("Inside thread\n");
}

int main()
{
    pthread_t TID;
    int ret = 0;

    ret = pthread_create(&TID,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc, // Address of callback function, function gets executed when thread gets scheduled
                          NULL);      // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    printf("Thread is created with ID : %d\n",TID);  //parent gela ki thread pan marto!!

    return 0;
}

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>

// void* thread_function(void* arg) {
//     printf("Thread is running\n");
//     return NULL;
// }

// int main() {
//     pthread_t thread;
//     pthread_attr_t attr;
//     size_t stack_size;
    
//     // Initialize thread attributes
//     pthread_attr_init(&attr);
    
//     // Set thread stack size
//     stack_size = 1024 * 1024; // 1 MB
//     pthread_attr_setstacksize(&attr, stack_size);
    
//     // Create a new thread with the specified attributes
//     if (pthread_create(&thread, &attr, thread_function, NULL) != 0) {
//         perror("pthread_create");
//         return EXIT_FAILURE;
//     }
    
//     // Wait for the thread to finish
//     pthread_join(thread, NULL);
    
//     // Destroy the thread attributes
//     pthread_attr_destroy(&attr);
    
//     return EXIT_SUCCESS;
// }
