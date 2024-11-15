// This program demonstate renaming a file or directory

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main()
{
	int ret;
	int fd;
	// This system call accept first parameter as already existing
	// file name and second parameter is a new file name
	// This system call only change the file name in the directory.

	ret = rename("Demoo.txt","renamefile.txt");
	if(ret == -1)
	{
		printf("Unable to rename file\n");
		return -1;
	}
	printf("File renamed\n");
	// Now we can open the file with new name
	fd = open("renamefile.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");	
		return -1;
	}
	printf("File opened\n");
	
	return 0;
}
