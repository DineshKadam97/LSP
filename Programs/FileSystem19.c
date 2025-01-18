#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    if(argc != 2)
    {
        printf("Insufficient arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)  //failure cases : 1)directory ch nahi 2)open karnyachi oermission nahi 3)Directory dilelya thikani nahi, dusrikde aahe pan kernel la te kalat nahi.
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("----------------------------------------------------------\n");
    printf("Entries from the directory file are : \n");
    printf("----------------------------------------------------------\n");
    printf("File Name \t\t Inode Number\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%20s : %d \n",entry->d_name, entry->d_ino);
    }
    printf("----------------------------------------------------------\n");

    closedir(dp);
    return 0;
}

// struct dirent {
//     ino_t d_ino;           // Inode number
//     off_t d_off;           // Offset to the next dirent
//     unsigned short d_reclen; // Length of this record
//     unsigned char d_type;    // Type of file
//     char d_name[256];      // Filename (null-terminated)
// };