/* 

This program demonstates enviornment list of our program.

The environment list is an array of character pointers, with each pointer 
containing the address of a null-terminated C string.
The address of the array of pointers is contained in the global variable environ.
We can access that global variable from our program.

Envoirnment list contains following things :

USER
	The name of the logged-in user.
LOGNAME
	The name of the logged-in user.
HOME
	A user's login directory, set by login from the password file passwd.
PATH
	The sequence of directory prefixes that sh and many other programs apply 
	in searching for a file known by an incomplete path name.
PWD
	The current working directory. Set by some shells.
SHELL
	The file name of the user's login shell.
*/

#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) // environment list can only be read if ur code is in native languages
{
	int index = 0;
	
	while (envp[index])
	{
		printf("%s\n", envp[index++]);
	}
}