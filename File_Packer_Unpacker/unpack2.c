#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

struct FileInfo {
    char FName[100]; // File name
    int FSize;       // File size
};

int main() {
    char PackedFile[100] = {'\0'};
    char outputDir[100] = {'\0'};
    struct FileInfo fobj;
    int fd = 0, destfd = 0;
    char buffer[1024];
    int bytesToRead = 0, bytesRead = 0;

    printf("Enter the path of the packed file to unpack:\n");
    scanf("%s", PackedFile);

    printf("Enter the path of the directory to recreate the files:\n");
    scanf("%s", outputDir);

    mkdir(outputDir, 0755); // Create the directory if it doesn't exist

    fd = open(PackedFile, O_RDONLY);
    if (fd == -1) {
        perror("Unable to open the packed file");
        return -1;
    }

    while (read(fd, &fobj, sizeof(fobj)) > 0) { // Read metadata
        char filePath[200] = {'\0'};
        sprintf(filePath, "%s/%s", outputDir, fobj.FName);

        destfd = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (destfd == -1) {
            perror("Unable to create the output file");
            continue;
        }

        bytesToRead = fobj.FSize;
        while (bytesToRead > 0) {
            bytesRead = read(fd, buffer, sizeof(buffer) < bytesToRead ? sizeof(buffer) : bytesToRead);
            write(destfd, buffer, bytesRead);
            bytesToRead -= bytesRead;
        }

        close(destfd);
    }

    close(fd);

    printf("Unpacking completed successfully.\n");
    return 0;
}

