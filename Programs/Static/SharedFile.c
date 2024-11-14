#include"SharedFile.h"

int Addition(int iNo1, int iNo2)
{
    int iAns = 0;
    iAns = iNo1 + iNo2;
    return iAns;
}


// create .o file from .c file
// gcc -c SharedFile.c -o SharedFile.o   -c means compile kar aani thamb

// create .a file from .o file 
//ar rcs SharedFile.a SharedFile.o      ar for archive   rcs runtime compile kar

// To compile the client file
// gcc -static Client.c -o Myeyxe SharedFile.a
