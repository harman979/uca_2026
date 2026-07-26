#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    int inputfd, outputfd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open source file
    inputfd = open(argv[1], O_RDONLY);
    if (inputfd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    // Open/Create destination file
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;   // rw-r--r--

    outputfd = open(argv[2], openFlags, filePerms);
    if (outputfd == -1) {
        perror("Error opening destination file");
        close(inputfd);
        exit(EXIT_FAILURE);
    }

    // Copy data
    while ((numRead = read(inputfd, buf, BUF_SIZE)) > 0) {

        if (write(outputfd, buf, numRead) != numRead) {
            perror("Error writing to destination file");
            close(inputfd);
            close(outputfd);
            exit(EXIT_FAILURE);
        }
    }

    // Check for read error
    if (numRead == -1) {
        perror("Error reading source file");
    }

    // Close files
    close(inputfd);
    close(outputfd);

    return 0;
}
