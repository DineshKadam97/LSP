#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/resource.h>

extern char **environ;

int main()
{
    char **env = environ;

    printf("Environment of running process is : \n"); //all information of a process stored in global variable environ 
                                                        //information : home directory, parent directory, parent kon aahe etc
    for(;*env != NULL; env++)
    {
        printf("%s : \n",*env);
    }
    
    return 0;
}

