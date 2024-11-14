#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* Increment(void* ptr)
{
  printf("Inside Increment\n");
  int iNo = *(int*)ptr;
  int *result = malloc(sizeof(int));
  *result = ++iNo;  // Use pre-increment to reflect the change
  pthread_exit(result);
}

void* Decrement(void* ptr)
{
  printf("Inside Decrement\n");
  int iNo = *(int*)ptr;
  int *result = malloc(sizeof(int));
  *result = --iNo;  // Use pre-decrement to reflect the change
  pthread_exit(result);
}

int main()
{
  void* Arr[2] = {Increment, Decrement};
  int iNo[] = {10, 21};
  pthread_t TID[2];  // Declare thread IDs here
  
  int* Value = NULL;

  for(int i = 0; i < 2; i++)
  {
    pthread_create(&TID[i], NULL, Arr[i], &iNo[i]);
  }
  
  for(int i = 0; i < 2; i++)
  {
    pthread_join(TID[i], (void**)&Value);
    printf("Value is: %d\n", *Value);
    free(Value);  // Free the allocated memory
  }
  
  return 0;
}

