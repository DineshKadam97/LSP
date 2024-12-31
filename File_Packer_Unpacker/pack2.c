#include <stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

struct FileInfo {
    char FName[100]; // File name
    int FSize;       // File size
};

int main() {
    char directory[100] = {'\0'};
    char PackedFile[100] = {'\0'};
    struct DIR* dp = NULL;
    struct dirent* entry = NULL;
    struct stat sobj;
    struct FileInfo fobj;
    int fd = 0, srcfd = 0;
    char buffer[1024];
    char filePath[200] = {'\0'}; // Declare filePath outside the loop
    int readBytes = 0;

    printf("Enter the path of the directory you want to pack:\n");
    scanf("%s", directory);

    dp = opendir(directory);
    if (dp == NULL) {
        perror("Unable to open the directory");
        return -1;
    }

    printf("Enter the name of the packed file to create:\n");
    scanf("%s", PackedFile);

    fd = open(PackedFile, O_WRONLY);
    if (fd == -1) {
        perror("Unable to create the packed file");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Process regular files only
            sprintf(filePath, "%s/%s", directory, entry->d_name); // Update filePath for this file

            stat(filePath, &sobj);
            strcpy(fobj.FName, entry->d_name);
            fobj.FSize = sobj.st_size;

            write(fd, &fobj, sizeof(fobj)); // Write metadata

            srcfd = open(filePath, O_RDONLY);
            if (srcfd == -1) {
                perror("Unable to open the source file");
                continue;
            }

            while ((readBytes = read(srcfd, buffer, sizeof(buffer))) > 0) {
                write(fd, buffer, readBytes); // Write file data
            }

            close(srcfd);
        }
    }

    close(fd);
    closedir(dp);

    printf("Packing completed successfully.\n");
    return 0;
}

