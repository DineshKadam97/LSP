// This program demonstates changing the file permisssions by using chmod 
// and fchmod

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<unistd.h>

int main( )
{
	int ret;
	int fd;

	// This function accept file name as first parameter and permissions 
	// to be set as second parameter.
	// For second parameter there are predefined macros available
	// In this example we are changing permissions of file first.txt 
	// as read,write,execute for the user.

	ret = chmod("Demoo.txt",S_IRWXU); //owner ssaglya permissions change karu shakto bakiche nahi

	if(ret == -1)
	{
		printf("Unable to change the permission\n");
	}

	// There are some other permissions flags available as
	/*
	S_ISUID set-user-ID on execution
	S_ISGID set-group-ID on execution
	S_ISVTX saved-text (sticky bit)
	S_IRWXU read, write, and execute by user (owner)
	S_IRUSR read by user (owner)
	S_IWUSR write by user (owner)
	S_IXUSR execute by user (owner)
	S_IRWXG read, write, and execute by group
	S_IRGRP read by group
	S_IWGRP write by group
	S_IXGRP execute by group
	S_IRWXO read, write, and execute by other (world)
	S_IROTH read by other (world)
	S_IWOTH write by other (world)
	S_IXOTH execute by other (world)
	*/

	// IF file is already opened then we can use the function fchmod as it does same activity.
	// This function accept first parameter as a file descriptor and second parameter as a permissions to be set.

	fd = open("Demoo.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
	}

	// In this case we are setting write permission for the user
	ret = fchmod(fd,S_IWUSR);
	if(ret == -1)
	{
		printf("Unable to change the permission\n");
	}
	printf("\nPermissions changed\n");
	return 0;
}
