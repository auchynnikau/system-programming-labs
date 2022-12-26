#include "tchar.h"
#include <windows.h>
#include <iostream>
#include "string.h"

using namespace std;

//struct Students {
//    string name;
//    string age;
//};
//
//
//int main()
//{
//    setlocale(LC_ALL, "RUS");
//
//    int n = 2;
//    Students** ArrayStr = (Students**)malloc(n * sizeof(Students*));
//
//    if (!ArrayStr)
//    {
//        std::cout << "\nНедостаточно памяти";
//        std::cout << "\nНажмите любую клавишу для завершения программы ...\n";
//
//        return 0;
//    }
//
//    std::cout << "Введите имя и возраст: " << std::endl;
//    for (int i = 0; i < n; i++) {
//        ArrayStr[i] = (Students*)malloc(n * sizeof(Students));
//        for (int j = 0; j < n; j++) {
//            std::cout << "Имя: ";
//            std::cin >> ArrayStr[i][j].name;
//            std::cout << "Возраст: ";
//            std::cin >> ArrayStr[i][j].age;
//        }
//    }
//
//    int k = 1;
//
//    std::cout << "\n№\t" << "Имя\t" << "Возраст\t\n";
//
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            std::cout << "-----------------------------" << std::endl;
//            std::cout << k << "\t" << ArrayStr[i][j].name << "\t" << ArrayStr[i][j].age << std::endl;
//            k++;
//        }
//    }
//
//    free(ArrayStr);
//    return 0;
//}

int main()
{
    setlocale(LC_ALL, "RUS");

    int n = 2;

    std::string** str = (std::string**)malloc(n * sizeof(std::string*));

    if (!str)
    {
        std::cout << "\nНедостаточно памяти";
        std::cout << "\nНажмите любую клавишу для завершения программы ...\n";

        return 0;
    }

    std::cout << "Введите строку" << std::endl;
    for (int i = 0; i < n; i++) {
        str[i] = new std::string;
        getline(std::cin, *(str[i]));
    }

    for (int i = 0; i < n; i++) {
        std::cout << "Строка №" << i + 1 << ": " << *(str[i]) << std::endl;
    }

    free(str);
    //_getch();
    return 0;
}
