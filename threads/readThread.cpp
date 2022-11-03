#include <windows.h>
#include <iostream>
#include "string.h"

DWORD WINAPI readingThread(void* lpParameter)
{
    HANDLE* counterAddress = (HANDLE*)lpParameter;
    HANDLE counter = *counterAddress;
    printf("\n Counter: %d", counter);
    return 0;
}

DWORD WINAPI writingThread(void* lpParameter)
{
    int* counterAddress = (int*)lpParameter;
    int counter = *counterAddress;
    DWORD threadId;
    while (counter < 30)
    {
        HANDLE thread = CreateThread(0, 0, readingThread, (void*)&counter, 0, &threadId);
        Sleep(300);
        TerminateThread(thread, 0);
        counter++;
    }
    return 0;
}

int minor(int argc, TCHAR* argv[])
{
    int counter = 0;
    DWORD threadId;
    HANDLE thread = CreateThread(0, 0, writingThread, (void*)&counter, 0, &threadId);
    Sleep(15000);
    TerminateThread(thread, 0);
    return 0;
}
