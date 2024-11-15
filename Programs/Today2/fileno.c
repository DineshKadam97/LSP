/*
	This program demonsate how to retrive file descrptor from th FILE pointer
*/

#include<stdio.h>

int main()
{
	FILE *fp;
	int fd;

	// Open file
	fp = fopen("file.txt","r");
	if(fp == NULL)
	{
		printf("Unable to open the file\n");
		return -1;
	}

	// This function returns file descripter which is allocated for the file.
	fd = fileno(fp);
	// First parameter :	File pointer
	if(fd == -1)
	{
		printf("Unable to get file descriptor\n");
		return -1;
	}

	printf("File descriptor is %d\n",fd);

	return 0;
}
