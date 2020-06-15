#include <windows.h>
#include <stdio.h>

#define NO_THREADS 2

DWORD WINAPI Thread1Worker(LPVOID lpParam)
{
    for (int i=0; i<10; i++)
    {
        printf("%d\n", 2*i);
        Sleep(1000);
    }
    return 0;
}

DWORD WINAPI Thread2Worker(LPVOID lpParam)
{
    for (int i=0; i<10; i++)
    {
        printf("%d\n", 2*i+1);
        Sleep(1000);
    }
    return 0;
}

int main()
{
    HANDLE hThread[NO_THREADS];
    DWORD dwThreadId[NO_THREADS];

    hThread[0] = CreateThread(
        NULL,                   //Security attributes
        0,                      //Default stack size
        Thread1Worker,          //Worker function
        NULL,                   //Arguments for thread function
        0,                      //Default creation flag
        &dwThreadId[0]
    );

    hThread[1] = CreateThread(
        NULL,                   //Security attributes
        0,                      //Default stack size
        Thread2Worker,          //Worker function
        NULL,                   //Arguments for thread function
        0,                      //Default creation flag
        &dwThreadId[1]
    );

    WaitForMultipleObjects(NO_THREADS, hThread, TRUE, INFINITE);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);

    return 0;
}