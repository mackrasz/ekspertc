#include <windows.h>
#include <stdio.h>

#define NO_THREADS 2

int sum;
CRITICAL_SECTION cs;

DWORD WINAPI ThreadWorker(LPVOID lpParam)
{
    for (int i=0; i<100000; i++)
    {
        EnterCriticalSection(&cs);
        sum = sum + 1;
        LeaveCriticalSection(&cs);
    }
    return 0;
}


int main()
{
    HANDLE hThread[NO_THREADS];
    DWORD dwThreadId[NO_THREADS];

    sum = 0;
    InitializeCriticalSection(&cs);

    hThread[0] = CreateThread(
        NULL,                   //Security attributes
        0,                      //Default stack size
        ThreadWorker,          //Worker function
        NULL,                   //Arguments for thread function
        0,                      //Default creation flag
        &dwThreadId[0]
    );

    hThread[1] = CreateThread(
        NULL,                   //Security attributes
        0,                      //Default stack size
        ThreadWorker,          //Worker function
        NULL,                   //Arguments for thread function
        0,                      //Default creation flag
        &dwThreadId[1]
    );

    WaitForMultipleObjects(NO_THREADS, hThread, TRUE, INFINITE);
    DeleteCriticalSection(&cs);

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);

    printf("sum=%d\n", sum);

    return 0;
}