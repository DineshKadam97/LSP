#include<stdio.h>
#include<fcntl.h> //open sathi
#include<unistd.h> // dup sathi

int main()
{
    int fd = 0;
    int fdnew = 0;

    fd = open("Demo.txt",O_RDONLY);

    printf("File Opened with FD : %d\n",fd);

    fdnew = dup(fd);   //duplicate chavi roomamate ch example ekach UAREA amdhey 2 Fds tayar hotat
    printf("Duplicate FD is : %d\n",fdnew);

    return 0;
} 