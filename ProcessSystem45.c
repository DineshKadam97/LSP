#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    int PID = 0;

    Ret = fork(); //2 return values ek child la(return value 0) aani ek parentla(child cha PID)

    if(Ret == 0)        // Child
    {
        printf("Child process is running\n");
        printf("Child says : PID of parent process is : %d\n",getppid());   // 3831
        printf("Child says : PID of child process is : %d\n",getpid());     // 3832
    }
    else                // Parent
    {
        printf("Parent process is running\n");
        printf("Parent says : PID of child process is : %d\n",Ret); // 3832
        printf("Parent says : PID of parent process is : %d\n",getpid());   // 3831
        printf("Parent says : PID of parent process of parent ie Terminal is : %d\n",getppid()); // 3669
    }
    
    return 0;
}