/////////////////////////////////////////////////////////////////////////////////////////////
//
//  Problem Statement : Write  a program to display the environment of a running process.
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

extern char **environ;

int main()
{
    char **env = NULL;
    env = environ;

    for(; env != NULL; env++)
    {
        printf("%s : \n",*env);
    }

    return 0;
}
