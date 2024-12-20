// Server for shared memory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/shm.h>

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int Key = 1234;
    char *ptr = NULL;

    printf("Server application running...\n");

    shmid = shmget(Key,shmsize,IPC_CREAT | 0666);

    printf("Shared memory allocated succesfully...\n");

    ptr = shmat(shmid,NULL,0); //shared memory attach karne

    if(ptr != NULL)
    {
        printf("Shared memory atached succesfully...\n");
    }
    
    return 0;
}