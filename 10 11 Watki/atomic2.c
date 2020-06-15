#include <windows.h>
#include <stdio.h>

#define NO_THREADS 2

int sum;
int flag1;
int flag2;

DWORD WINAPI Thread1Worker(LPVOID lpParam)
{
    for (int i=0; i<100000; i++)
    {
        flag1 = 1;
        while (flag2)
            Sleep(10);

        sum = sum + 1;
        flag1 = 0;
    }
    return 0;
}

DWORD WINAPI Thread2Worker(LPVOID lpParam)
{
    for (int i=0; i<100000; i++)
    {
        flag2 = 1;
        while (flag1)
            Sleep(10);

        sum = sum + 1;
        flag2 = 0;
    }
    return 0;
}


int main()
{
    HANDLE hThread[NO_THREADS];
    DWORD dwThreadId[NO_THREADS];

    sum = 0;
    flag1 = 0;
    flag2 = 0;

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

    printf("sum=%d\n", sum);

    return 0;
}