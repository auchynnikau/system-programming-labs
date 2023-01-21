#include "tchar.h"
#include <windows.h>
#include <iostream>
#include "string.h"

using namespace std;

struct students {
    string name;
    string age;
};

int handleStudents()
{
    setlocale(lc_all, "ENG");

    int n = 2;

    students** arraystr = (students**)malloc(n * sizeof(students*));

    if (!arraystr)
    {
        std::cout << "\nError! Lack of memory!";
        std::cout << "\nPress Enter to exit the program...\n";

        return 0;
    }

    std::cout << "Type name and address: " << std::endl;

    for (int i = 0; i < n; i++) {
        arraystr[i] = (students*)malloc(n * sizeof(students));

        for (int j = 0; j < n; j++) {
            std::cout << "Name: ";
            std::cin >> arraystr[i][j].name;
            std::cout << "Age: ";
            std::cin >> arraystr[i][j].age;
        }
    }

    int k = 1;

    std::cout << "\n№\t" << "Name\t" << "Age\t\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "-----------------------------" << std::endl;
            std::cout << k << "\t" << arraystr[i][j].name << "\t" << arraystr[i][j].age << std::endl;
            k++;
        }
    }

    free(arraystr);
    return 0;
}

int main()
{
    setlocale(LC_ALL, "ENG");

    int n = 2;

    std::string** str = (std::string**)malloc(n * sizeof(std::string*));

    if (!str)
    {
        std::cout << "\nError! Lack of memory!";
        std::cout << "\nPress Enter to exit the program...\n";

        return 0;
    }

    std::cout << "Type string: " << std::endl;
    for (int i = 0; i < n; i++) {
        str[i] = new std::string;
        getline(std::cin, *(str[i]));
    }

    for (int i = 0; i < n; i++) {
        std::cout << "String: " << i + 1 << ": " << *(str[i]) << std::endl;
    }

    free(str);
    _getch();

    return 0;
}
