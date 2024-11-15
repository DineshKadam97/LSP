#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, ret = 0;
    struct stat obj1, obj2;
    char Buffer1[1024];
    char Buffer2[1024];
    int iCnt = 0;

    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);
    
    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are diffrent as sizes are diffrent\n");
        return -1;
    }

    while((ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        printf("Iteration no : %d\n",iCnt);
        iCnt++;
        ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("Both files are identical\n");
    }
    else
    {
        printf("Both files are diffrent\n");
    }

    close(fd1);
    close(fd2);

    return 0;
}