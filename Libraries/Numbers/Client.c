#include<stdio.h>
#include<stdbool.h>
#include<dlfcn.h>

typedef unsigned long int ULONG;

int main()
{
    int A = 0, B = 0;
    bool bRet = false;
    int iRet = 0;
    float fRet = 0.0f;
    ULONG uRet = 0;

    void *ptr = NULL;
    bool (*fptr1)(int);
    void (*fptr2)(int);
    int(*fptr3)(int);
    float(*fptr4)(int);
    ULONG (*fptr5)(int);
    ULONG (*fptr6)(int ,int );

    printf("Please, enter the number\n");
    scanf("%d", &A);

    ptr = dlopen("/home/dinesh/Desktop/Libraries/Numbers/library.so", RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("unable to load library\n");
        return -1;
    }

    fptr1 = dlsym(ptr, "CheckEven");
    if(fptr1 == NULL)
    {
        printf("Unable to load address of function CheckEven\n");
        return -1;
    }

    bRet = fptr1(A);
    if(bRet == true)
    {
        printf("%d is an even number\n", A);
    }
    else
    {
        printf("%d is not an even number\n", A);
    }

    fptr1 = dlsym(ptr, "CheckOdd");
    if(fptr1 == NULL)
    {
        printf("Unable to load address of function CheckOdd\n");
        return -1;
    }

    bRet = fptr1(A);
    if(bRet == true)
    {
        printf("%d is an odd number\n", A);
    }
    else
    {
        printf("%d is not an odd number\n", A);
    }

    fptr1 = dlsym(ptr, "CheckPrime");
    if(fptr1 == NULL)
    {
        printf("Unable to load address of function CheckPrime\n");
        return -1;
    }

    bRet = fptr1(A);
    if(bRet == true)
    {
        printf("%d is a prime number\n", A);
    }
    else
    {
        printf("%d is not a prime number\n", A);
    }

    fptr1 = dlsym(ptr, "CheckPerfect");
    if(fptr1 == NULL)
    {
        printf("Unable to load address of function CheckPerfect\n");
        return -1;
    }

    bRet = fptr1(A);
    if(bRet == true)
    {
        printf("%d is a perfect number\n", A);
    }
    else
    {
        printf("%d is not a perfect number\n", A);
    }

    fptr2 = dlsym(ptr, "DisplayFactors");
    if(fptr2 == NULL)
    {
        printf("Unable to load address of DisplayFactors\n");
        return -1;
    }
    printf("Factors of %d are : ", A);
    fptr2(A);

    fptr3 = dlsym(ptr, "FactorsSum");
    if(fptr2 == NULL)
    {
        printf("Unable to load address of function FactorsSum\n");
        return -1;
    }

    iRet = fptr3(A);
    printf("Sum of the factors of %d is : %d\n", A, iRet);

    fptr4 = dlsym(ptr, "FactorsAvg");
    if(fptr2 == NULL)
    {
        printf("Unable to load address of function FactorsAvg\n");
        return -1;
    }

    fRet = fptr4(A);
    printf("Average of the factors of %d is : %f\n", A, fRet);

    fptr5 = dlsym(ptr, "Factorial");
    if(fptr2 == NULL)
    {
        printf("Unable to load address of function Factorial\n");
        return -1;
    }

    uRet = fptr5(A);
    printf("Factorial of %d is : %lu\n", A, uRet);

    fptr6 = dlsym(ptr, "Exponent");
    if(fptr2 == NULL)
    {
        printf("Unable to load address of function Factorial\n");
        return -1;
    }

    printf("Please, enter the power\n");
    scanf("%d", &B);

    uRet = fptr6(A, B);
    printf("%d raise to %d is : %lu\n", A, B, uRet);

    return 0;
}