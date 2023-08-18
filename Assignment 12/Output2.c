// Client for shared memory

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h> 
#include<sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int Key = 1234;
    char *ptr = NULL;

    printf("ChildProcess2 is running as a Client applocation......\n");

    shmid = shmget(Key,shmsize,0666); 

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory attached succesfully...\n");
    }

    while(*ptr != '\0')
    {
        printf("%c",*ptr);
        ptr++;
    }

    shmdt(shmid);

    printf("\n");

    return 0;
}
