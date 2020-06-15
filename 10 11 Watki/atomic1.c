#include <windows.h>
#include <stdio.h>

#define NO_THREADS 2

int sum;
int lock;

DWORD WINAPI ThreadWorker(LPVOID lpParam)
{
    for (int i=0; i<100000; i++)
    {
        while (lock)
            Sleep(10);
        lock = 1;
        sum = sum + 1;
        lock = 0;
    }
    return 0;
}


int main()
{
    HANDLE hThread[NO_THREADS];
    DWORD dwThreadId[NO_THREADS];

    sum = 0;
    lock = 0;

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

    CloseHandle(hThread[0]);
    CloseHandle(hThread[1]);

    printf("sum=%d\n", sum);

    return 0;
}