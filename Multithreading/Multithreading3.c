#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct Info {
    int i;
    int Brr[10];
};

void* Sum(void *ptr) {
    struct Info* iptr = (struct Info*)ptr;
    int iSize = iptr->i;
    int iSum = 0;

    for (int i = 0; i < iSize; i++) {
        iSum += iptr->Brr[i];
    }

    int* result = malloc(sizeof(int)); // Corrected: Dynamically allocate memory
    *result = iSum;
    printf("Sum: %d\n", iSum);
    pthread_exit(result);
}

void* Average(void *ptr) {
    struct Info* iptr = (struct Info*)ptr;
    int iSize = iptr->i;
    int iSum = 0;

    for (int i = 0; i < iSize; i++) {
        iSum += iptr->Brr[i];
    }

    int* result = malloc(sizeof(int)); // Corrected: Dynamically allocate memory
    *result = iSum / iSize;
    printf("Average: %d\n", *result);
    pthread_exit(result);
}

void* MaxNumber(void *ptr) {
    struct Info* iptr = (struct Info*)ptr;
    int iSize = iptr->i;
    int iMax = iptr->Brr[0];

    for (int i = 1; i < iSize; i++) {
        if (iptr->Brr[i] > iMax) {
            iMax = iptr->Brr[i];
        }
    }

    int* result = malloc(sizeof(int)); // Corrected: Dynamically allocate memory
    *result = iMax;
    printf("Max: %d\n", iMax);
    pthread_exit(result);
}

void* MinNumber(void *ptr) {
    struct Info* iptr = (struct Info*)ptr;
    int iSize = iptr->i;
    int iMin = iptr->Brr[0];

    for (int i = 1; i < iSize; i++) {
        if (iptr->Brr[i] < iMin) {
            iMin = iptr->Brr[i];
        }
    }

    int* result = malloc(sizeof(int)); // Corrected: Dynamically allocate memory
    *result = iMin;
    printf("Min: %d\n", iMin);
    pthread_exit(result);
}

void* SumPrime(void *ptr) {
    struct Info* iptr = (struct Info*)ptr;
    int iSize = iptr->i;
    int iSumP = 0;

    for (int i = 0; i < iSize; i++) {
        int num = iptr->Brr[i];
        if (num <= 1) continue;

        int isPrime = 1;
        for (int j = 2; j * j <= num; j++) {
            if (num % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            iSumP += num;
        }
    }

    int* result = malloc(sizeof(int)); // Corrected: Dynamically allocate memory
    *result = iSumP;
    printf("Sum of Primes: %d\n", iSumP);
    pthread_exit(result);
}

void* SumPerfect(void *ptr) {
    struct Info* iptr = (struct Info*)ptr;
    int iSize = iptr->i;
    int iSumPer = 0;

    for (int i = 0; i < iSize; i++) {
        int num = iptr->Brr[i];
        int sum = 1; // Start with 1 as a proper divisor

        for (int j = 2; j <= num / 2; j++) {
            if (num % j == 0) {
                sum += j;
            }
        }

        if (sum == num && num != 1) {
            iSumPer += num;
        }
    }

    int* result = malloc(sizeof(int)); // Corrected: Dynamically allocate memory
    *result = iSumPer;
    printf("Sum of Perfect Numbers: %d\n", iSumPer);
    pthread_exit(result);
}

int main() {
    pthread_t TID[6];

    void* Arr[] = {Sum, Average, MaxNumber, MinNumber, SumPrime, SumPerfect};
    int* iValue = NULL;

    struct Info iobj;
    iobj.i = 10;

    int values[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    for (int j = 0; j < 10; j++) {
        iobj.Brr[j] = values[j];
    }

    for (int i = 0; i < 6; i++) {
        pthread_create(&TID[i], NULL, Arr[i], &iobj);
    }

    for (int i = 0; i < 6; i++) {
        pthread_join(TID[i], (void**)&iValue);
        printf("Result: %d\n", *iValue);
        free(iValue); // Free the allocated memory
       // iValue = NULL;
    }

    return 0;
}

