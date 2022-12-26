#include <windows.h>
#include <iostream>


int main()
{
	HANDLE hslot;

	const wchar_t* slotname = TEXT("\\\\.\\mailslot\\demoslot");
	hslot = CreateFile(slotname, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);

	if (hslot == INVALID_HANDLE_VALUE)
	{

		std::cout << "SLOT WRITING FAILED" << std::endl;
		std::cout << "PRESS KEY TO FINICH" << std::endl;
		std::cin.get();
		return 0;
	}

	while (true) {
		char str[33];

		std::cout << "STR: ";
		std::cin >> str;

		DWORD dwBytesWrite;
		if (!WriteFile(hslot, &str, sizeof(str), &dwBytesWrite, NULL))
		{
			std::cout << "WRITE FAILED" << std::endl;
			CloseHandle(hslot);
			std::cout << "PRESS KEY TO FINICH" << std::endl;
			std::cin.get();
			return 0;
		}

		std::cout << "Data WRITTEN TO BOX: " << str << std::endl;
	}

	std::cout << "PRESS KEY TO FINICH" << std::endl;
	CloseHandle(hslot);
	std::cin.get();
	return 0;
}
