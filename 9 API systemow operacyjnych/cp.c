#include <stdio.h>

#define BUFFSIZE 1024

int main(int argc, char** argv)
{
    FILE* inputFile;
    FILE* outputFile;
    int noReadBytes;
    int noWrittenBytes;
    char buffer[BUFFSIZE];

    if (argc != 3)
    {
        printf("Usage: cp input output\n");
        return 1;
    }

    inputFile = fopen(argv[1], "rb");
    if (inputFile == NULL)
    {
        printf("Cannot open file %s\n", argv[1]);
        return 2;
    }

    outputFile = fopen(argv[2], "wb");
    if (outputFile == NULL)
    {
        printf("Cannot open file %s\n", argv[2]);
        return 3;
    }

    while((noReadBytes = fread(buffer, sizeof(char), BUFFSIZE, inputFile)) > 0)
    {
        noWrittenBytes = fwrite(buffer, sizeof(char), noReadBytes, outputFile);
        if (noWrittenBytes != noReadBytes)
        {
            printf("Error during copying the file\n");
            return 4;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;

}