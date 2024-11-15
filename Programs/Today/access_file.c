// This program demonstates accessibility of the files

#include<string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	char name[255];

// access() checks whether the calling process can access the file pathname.  If pathname is a symbolic link, it is dereferenced.
//On  success  (all requested permissions granted), zero is returned.  
// On error (at least one bit in mode asked for a permission that is denied, or some other error occurred), -1 is returned,

	if (access(argv[1 ],R_OK) < 0)
	{
		printf("Our process can not access this file for reading purpose\n");
	}
	else
	{
		printf("Our process has read access\n");
	}

	if (access(argv[1], W_OK) < 0)
	{
		printf("Our process can not access this file for writing purpose\n");
	}
	else
	{
		printf("Our process has write access\n");
	}
// also check for an execute permission...
	if (access(argv[1], X_OK) < 0)
	{
		printf("Our process can not access this file for executing purpose\n");
	}
	else
	{
		printf("Our process has executing access\n");
	}

	return 0;
}
