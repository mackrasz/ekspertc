#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFSIZE 1024

int main(int argc, char** argv)
{
    int inputFile;
    int outputFile;
    int noReadBytes;
    int noWrittenBytes;
    char buffer[BUFFSIZE];

    if (argc!=3)
    {
        printf("Usage: cp input output\n");
        return 1;
    }

    inputFile = open(argv[1], O_RDONLY);
    if (inputFile == -1)
    {
        printf("Cannot open file %s\n", argv[1]);
        return 2;
    }

    outputFile = creat(argv[2], 0666);
    if (outputFile == -1)
    {
        printf("Cannot create file %s\n", argv[2]);
        return 3;
    }

    while ((noReadBytes = read(inputFile, buffer, BUFFSIZE)) > 0)
    {
        noWrittenBytes = write(outputFile, buffer, noReadBytes);
        if (noWrittenBytes != noReadBytes)
        {
            printf("Error during copying the files\n");
            return 4;
        }
    }

    close(inputFile);
    close(outputFile);

    return 0;
}