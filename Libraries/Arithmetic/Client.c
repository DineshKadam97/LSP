#include<stdio.h>
#include<dlfcn.h>

int main()
{
    int A = 0, B = 0;
    int iRet = 0;

    void *ptr1 = NULL;
    int (*fptr1)(int, int);

    ptr1 = dlopen("/home/dinesh/Desktop/Libraries/library1.so", RTLD_LAZY);
    if(ptr1 == NULL)
    {
       printf("Unable to load library\n");
       return -1;
    }
    
    fptr1 = dlsym(ptr1, "Addition");
    if(ptr1 == NULL)
    {
        printf("Unable to load address of function Addition\n");
        return -1;
    }

    printf("Please, enter the first number\n");
    scanf("%d", &A);

    printf("Please, enter the second number\n");
    scanf("%d", &B);

    iRet = fptr1(A, B);
    printf("Addition is : %d\n", iRet);

    fptr1 = dlsym(ptr1, "Substraction");
    if(ptr1 == NULL)
    {
        printf("Unable to load address of function Substraction\n");
        return -1;
    }
    iRet = fptr1(A, B);
    printf("Substraction is : %d\n", iRet);

    ptr1 = dlopen("/home/dinesh/Desktop/Libraries/library2.so", RTLD_LAZY);
    if(ptr1 == NULL)
    {
       printf("Unable to load library\n");
       return -1;
    }

    fptr1 = dlsym(ptr1, "Multiplication");
    if(ptr1 == NULL)
    {
        printf("Unable to load address of function Substraction\n");
        return -1;
    }
    iRet = fptr1(A, B);
    printf("Multiplication is : %d\n", iRet);

    fptr1 = dlsym(ptr1, "Division");
    if(ptr1 == NULL)
    {
        printf("Unable to load address of function Substraction\n");
        return -1;
    }
    iRet = fptr1(A, B);
    printf("Division is : %d\n", iRet);

    return 0;
}

