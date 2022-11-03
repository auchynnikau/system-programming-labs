#include "tchar.h" 
#include <windows.h> 
#include <iostream> 
#include "string.h" 
#include <tlhelp32.h> 

std::string fileProcessName;

bool AreEqual(const TCHAR* x, const TCHAR* y)
{
    while (*x == *y)
    {
        if (*x == _TEXT('\0'))
        {
            return true;
        }

        x++;
        y++;
    }

    return false;
}

bool IsProcessRunning()
{
    bool isRunning;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    process.dwSize = sizeof(PROCESSENTRY32);
    Process32First(snapshot, &process);

    if (AreEqual(process.szExeFile, fileProcessName.c_str()))
    {
        isRunning = true;
        return isRunning;
    }
    else
    {
        isRunning = false;
    }

    while (Process32Next(snapshot, &process))
    {
        if (AreEqual(process.szExeFile, fileProcessName.c_str()))
        {
            isRunning = true;
            return isRunning;
        }
        else
        {
            isRunning = false;
        }
    }

    return isRunning;
}

int main(int argc, _TCHAR* argv[])
{
    WIN32_FIND_DATA findData;
    HANDLE searchResult = INVALID_HANDLE_VALUE;

    std::string filePath = "D:\\Test\\";
    std::string fileName = "OfficeSetup*";
    std::string searchQuery = filePath + fileName;

    searchResult = FindFirstFile(searchQuery.c_str(), &findData);

    if (searchResult == INVALID_HANDLE_VALUE)
    {
        printf("Invalid file handle! Error is %u.\n", GetLastError());
    }
    else
    {
        std::wcout << "Search result: " << findData.cFileName << '\n';
        std::string file = filePath + findData.cFileName;
        fileProcessName = findData.cFileName;

        STARTUPINFO startupInfo;
        PROCESS_INFORMATION processInfo;
        ZeroMemory(&startupInfo, sizeof(STARTUPINFO));

        BOOL isProcessCreated = CreateProcess(NULL, (char*)file.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo);

        if (!isProcessCreated)
        {
            std::wcout << "Error! Cannot create process." << '\n';
        }

        FindClose(searchResult);

        if (IsProcessRunning())
        {
            std::wcout << "\nProcess is running!" << '\n';
        }
        else
        {
            std::wcout << "\nProcess is not running!" << '\n';
        }
    }

    system("pause");
    return 0;
}
