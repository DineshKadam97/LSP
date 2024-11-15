// This program demonstates creation of symbolic link means soft link.
// A symbolic link is a special type of file whose contents are a string
// that is the pathname another file, the file to which the link refers.
// Symbolic  links  are  files  that act as pointers to other files. But in case of hard link
// new name of the file gets added in directory with the same inode number.
// In user level symbolic links are called as shortcuts.

#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>

int main()
{
	int fd,ret;
	char buff[50];

	ret = symlink("/home/dinesh/Desktop/Today/NewDirectory/Demoo.txt","symmlink.txt");   //you can give absolute path too
	if(ret == -1)
	{
		printf("Unable to create symbolic link\n");
		return -1;
	}

	// If we create symbolic link for such a file which is not existing
	// then that type of link is called as dangling link.

	// As symbolic link contains path of another file we can read this file by 
	// using readlink system call.

	ret = readlink("symmlink.txt",buff,sizeof(buff));
	if(ret == 0)
	{
		printf("Unable to retrive ");
	}

	printf("Contents inside the symbolic link are %s\n",buff);

	// opening a symbolic link
	fd = open("symmlink.txt",O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}

	memset(buff,0,sizeof(buff));

	// When we read the symbolic link we get data inside the original file.

	ret = read(fd,buff,sizeof(buff));
	if(ret == 0)
	{
		printf("Unable to read contents\n");
		return -1;
	}

	printf("\nContents inside the symbolic link are : %s\n",buff);

	return 0;
}
