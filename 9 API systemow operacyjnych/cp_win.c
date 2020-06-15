#include <stdio.h>
#include <windows.h>

#define BUFFSIZE 1024

int main(int argc, char** argv)
{
    HANDLE inputFile;
    HANDLE outputFile;
    DWORD noReadBytes;
    DWORD noWrittenBytes;
    CHAR buffer[BUFFSIZE];

    if (argc != 3)
    {
        printf("Usage: cp input output\n");
        return 1;
    }
    
    inputFile = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ,
                NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (inputFile == INVALID_HANDLE_VALUE)
    {
        printf("Cannot open file %s\n", argv[1]);
        return 2;
    }            

    outputFile = CreateFile(argv[2], GENERIC_WRITE, 0,
                NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (outputFile == INVALID_HANDLE_VALUE)
    {
        printf("Cannot open file %s\n", argv[2]);
        return 3;
    }            

    while (ReadFile(inputFile, buffer, BUFFSIZE, &noReadBytes, NULL) && noReadBytes > 0)
    {
        WriteFile(outputFile, buffer, noReadBytes, &noWrittenBytes, NULL);
        if (noWrittenBytes != noReadBytes)
        {
            printf("Error during copying the file\n");
            return 4;
        }
    }

    CloseHandle(inputFile);
    CloseHandle(outputFile);
}