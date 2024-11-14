#include<stdio.h>
#include"SharedFile.h"

void Display()
{
    printf("Jay Ganesh...\n");
    printf("Ganpati Bappa Morya...\n");
}

// TO create .o file
// gcc -c -FPIC Sharedfile.c

// To create .so file
// gcc -shared -o library.so SharedFile.o
