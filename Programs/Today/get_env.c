/* 

This program demonstates use of getenv().

This function is used to retrive the value of perticular enviornment variable.
For that we have to pass name of that enviornment variable and it returns value of that variable.

Syntax :
char *getenv(const char *name);

We can use setenv() function to set the specific value.

*/

#include <stdio.h>
#include<stdlib.h>

int main()
{
	char *p;

	p = getenv("PWD");   // it returns char * (string as a return value)
	if(p == NULL)
	{
		printf("Unable to get value\n");
	}
	
	printf("Present Working Directory is : %s\n",p);

	p = NULL;

	p = getenv("SHELL");
	if(p == NULL)
	{
		printf("Unable to get value\n");
	}
	
	printf("Shell of our process is : %s\n",p);

	p = NULL;
	
	p = getenv("HOME");
	if(p == NULL)
	{
		printf("Unable to get value\n");
	}
	
	printf("Home directory is : %s\n",p);

	return 0;
}