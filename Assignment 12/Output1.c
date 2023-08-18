// Server for shared memory

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

    printf("ChildProcess1 is running as a Server application......\n");

    shmid = shmget(Key,shmsize,IPC_CREAT | 0666);  // IPC_CREAT to create shared 

    printf("Shared memory allocated succesfully...\n");

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory attached succesfully...\n");
    }

    *ptr = 'B';
    ptr++;

    *ptr = 'H';
    ptr++;

    *ptr = 'A';
    ptr++;

    *ptr = 'R';
    ptr++;
    
    *ptr = 'A';
    ptr++;

    *ptr = 'T';
    ptr++;

    printf("Data is written in shared memory succesfully...\n");

    return 0;
}
