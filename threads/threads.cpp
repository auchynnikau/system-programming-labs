#include <windows.h>
#include <iostream>
#include "string.h"

struct lpParameters {
    int initValue = 0;
    std::string threadName;
};

DWORD WINAPI initThread(void* lpParameter)
{
    lpParameters* parameters = static_cast<lpParameters*>(lpParameter);
    int counter = parameters->initValue;
 
    while (counter < 20)
    {
        Sleep(1000);
        counter++;
        std::cout << parameters->threadName << " Counter: " << counter << std::endl;
    }

    return 0;
}

int main() {
    lpParameters params1;
    lpParameters params2;

    params1.initValue = 5;
    params2.initValue = 5;
    params1.threadName = "\n Thread - 1";
    params2.threadName = "\n Thread - 2";
    
    DWORD thread1;
    DWORD thread2;
    
    HANDLE handle1 = CreateThread(0, 0, initThread, (LPVOID*)&params1, 0, &thread1);
    HANDLE handle2 = CreateThread(0, 0, initThread, (LPVOID*)&params2, 0, &thread2);
    
    Sleep(5000);
    printf("\n Main Process finished.");
    
    TerminateThread(handle1, 0);
    TerminateThread(handle2, 0);
    
    return 0;
}
