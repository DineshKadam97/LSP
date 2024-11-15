//Program to find the file type

#include<string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<unistd.h>

int main( )
{
	struct stat buf;
	char name[255];

	printf("\nEnter file name to check its type\n");
	scanf("%s",name);

	if (stat(name, &buf) < 0)
	{
		printf("Error while retriving statistics of file\n");
		return -1;
	}
	// There are macros defined which checks file type
	// If file type match then it returns true

	if (S_ISREG(buf.st_mode))
	{
		printf("Regular file");
	}
	else if (S_ISDIR(buf.st_mode))
	{
		printf("Directory");
	}
	else if (S_ISCHR(buf.st_mode))
	{
		printf("Character special fiel");
	}
	else if (S_ISBLK(buf.st_mode))
	{
		printf("Block special file");
	}
	else if (S_ISFIFO(buf.st_mode))
	{
		printf("FIFO");
	}
	else if (S_ISLNK(buf.st_mode))
	{
		printf("Symbolic link");
	}
	else if (S_ISSOCK(buf.st_mode))
	{
		printf("Socket");
	}
	else
	{
		printf("File type is unknown");
	}

printf("\n");
return 0;
}
