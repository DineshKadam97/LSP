//This application performs multithreading of the problems on the Digits, such as count total digits, see if number is pallindrome, check if particular digit is present in the number or not.

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<stdbool.h>

void* Total(void* ptr) {
    int iNo = *(int*)ptr;
    int iCount = 0;
  
    if(iNo < 0) {
        iNo = -iNo;
    }
  
    while(iNo != 0) {
        iCount++;
        iNo = iNo / 10;
    }
    int* result = malloc(sizeof(int));
    *result = iCount; 
    pthread_exit(result);
}

void* CheckDigit(void* ptr) {
    int iNo = *(int*)ptr;
    int iDigit = 0;
    bool isPresent = false;
  
    if(iNo < 0) {
        iNo = -iNo;
    }
  
    while(iNo != 0) {
        iDigit = iNo % 10;
        if(iDigit == 7) {
            isPresent = true;
            break;
        }
        iNo = iNo / 10;
    }
    bool* result = malloc(sizeof(bool));
    *result = isPresent; 
    pthread_exit(result);
}

void* MaxDigit(void* ptr) {
    int iNo = *(int*)ptr;
    int iDigit = 0, iMax = 0;
  
    if(iNo < 0) {
        iNo = -iNo;
    }
  
    while(iNo != 0) {
        iDigit = iNo % 10;
        if(iDigit > iMax) {
            iMax = iDigit;
        }
        iNo = iNo / 10;
    }
    int* result = malloc(sizeof(int));
    *result = iMax; 
    pthread_exit(result);
}

void* MinDigit(void* ptr) {
    int iNo = *(int*)ptr;
    int iDigit = 0, iMin = 9; 
  
    if(iNo < 0) {
        iNo = -iNo;
    }
  
    while(iNo != 0) {
        iDigit = iNo % 10;
        if(iDigit < iMin) {
            iMin = iDigit;
        }
        iNo = iNo / 10;
    }
    int* result = malloc(sizeof(int));
    *result = iMin; // Correctly store the min digit
    pthread_exit(result);
}

void* CheckPallindrome(void* ptr) {
    int iNo = *(int*)ptr;
    int iDigit = 0, iReverse = 0;
  
    if(iNo < 0) {
        iNo = -iNo;
    }
  
    int itemp = iNo;
    while(iNo != 0) {
        iDigit = iNo % 10;
        iReverse = iReverse * 10 + iDigit;
        iNo = iNo / 10;
    }
    bool isPallindrome = (itemp == iReverse);
    bool* result = malloc(sizeof(bool));
    *result = isPallindrome;
    pthread_exit(result);
}

void* ReverseNumber(void* ptr) {
    int iNo = *(int*)ptr;
    int iDigit = 0, iReverse = 0;
  
    if(iNo < 0) {
        iNo = -iNo;
    }
  
    while(iNo != 0) {
        iDigit = iNo % 10;
        iReverse = iReverse * 10 + iDigit;
        iNo = iNo / 10;
    }
    int* result = malloc(sizeof(int));
    *result = iReverse;
    pthread_exit(result);
}

int main() {
    pthread_t TID[6];
    int iNo = 56784;
    void* Arr[] = {Total, CheckDigit, CheckPallindrome, MaxDigit, MinDigit, ReverseNumber};
    void* result = NULL;
  
    for(int i = 0; i < 6; i++) {
        pthread_create(&TID[i], NULL, Arr[i], &iNo);       
    }
  
    for(int i = 0; i < 6; i++) {
        pthread_join(TID[i], &result);
         if (i == 1 || i == 2)
         { 
            printf("Result: %s\n", (*(bool*)result) ? "True" : "False");
         } 
         else 
         {
            printf("Result: %d\n", *(int*)result);
         }
    }  
  
    return 0;
}

