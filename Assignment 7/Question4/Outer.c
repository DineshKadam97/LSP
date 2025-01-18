#include<stdio.h>
#include"Outer.h"
#include<dlfcn.h>

int* OpenInnerFile()
{
    int *ptr = NULL;
    ptr = dlopen("/home/dinesh/Desktop/Assignments/Assignment7/innerlibrary.so", RTLD_LAZY);
    return ptr;
}