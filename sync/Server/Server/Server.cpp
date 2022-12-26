#include <windows.h>
#include <iostream>

int main()
{
	HANDLE hslot;
	const wchar_t* slotname = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateMailslot(slotname, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;

	}

	while (true)
	{
		std::cout << "SLOT IS WAITING" << std::endl;
		char nData[33];
		DWORD dwBytesRead;
		if (!ReadFile(hslot, &nData, sizeof(nData), &dwBytesRead, (LPOVERLAPPED)NULL))
		{
			std::cout << "READING SLOT FAILED" << std::endl;
			CloseHandle(hslot);
			std::cout << "PRESS KEY TO FINICH" << std::endl;
			std::cin.get();
			return 0;
		}

		std::cout << "Data Read :" << nData << std::endl;
	}

	std::cout << "PRESS KEY TO FINICH" << std::endl;
	CloseHandle(hslot);
	std::cin.get();
	return 0;


	return 0;
}
