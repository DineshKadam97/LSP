//Directory handler using multithreading

#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>


void* DeleteEmpty(void* ptr)
{
   DIR* dp = (DIR*) ptr;
   struct dirent* entry = NULL;
   struct stat sobj;
   char* FileName = NULL;
   size_t baselen = strlen("Demo")+2;
   
   while((entry = readdir(dp)) != NULL)
   {
     FileName = malloc(baselen + strlen(entry->d_name));
     if(FileName == NULL)
     {
       perror("Can not allocate memory\n");
       pthread_exit(NULL);
     }
     
     sprintf(FileName,"%s/%s","Demo",entry->d_name);
     stat(FileName,&sobj);
     if(sobj.st_size == 0)
     {
       printf("%20s %ld\n",entry->d_name, sobj.st_ino);
       remove(FileName);
     }
   }
   
   pthread_exit(NULL);
}

void* DeleteBig(void* ptr)
{
   DIR* dp = (DIR*) ptr;
   struct dirent* entry = NULL;
   struct stat sobj;
   char *FileName = NULL;
   size_t baselen = strlen("Demo")+2;
   printf("Big Files\n");
   
   while((entry = readdir(dp)) != NULL)
   {
     FileName = malloc(baselen + strlen(entry->d_name));
     if(FileName == NULL)
     {
       perror("Can not allocate memory\n");
       pthread_exit(NULL);
     }
     sprintf(FileName,"%s/%s","Demo",entry->d_name);
     stat(FileName,&sobj);
     if(sobj.st_size > 800)
     {
       printf("%20s %ld\n",entry->d_name, sobj.st_ino);
       remove(FileName);
     }
   }
   
   pthread_exit(NULL);
}

int main()
{
  pthread_t TID1, TID2;
  
  DIR* dp = NULL;
  
  dp = opendir("Demo");
  if(dp == NULL)
  {
    perror("Can not open directory\n");
    return -1;
  }
    rewinddir(dp);
  pthread_create(&TID1,
                 NULL,
                 DeleteEmpty,
                 dp);
                 
  pthread_join(TID1,NULL);
  
  rewinddir(dp);
  
  pthread_create(&TID2,
                 NULL,
                 DeleteBig,
                 dp);
                 
  pthread_join(TID2,NULL);
  printf("End of main threaad\n");
  
  pthread_exit(NULL);
  return 0;
}
