#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;
extern "C" {
    typedef bool(*FindAllCharsFunc)(const char*, const char*);
}

int main()
{
    setlocale(LC_ALL, "Rus");

    HINSTANCE load = LoadLibrary(L"DynamicLib.dll");
    if (load == NULL) {
        cerr << "Не удалось загрузить библиотеку!" << endl;
        return 1;
    }

    FindAllCharsFunc FindAllChars = (FindAllCharsFunc)GetProcAddress(load, "FindAllChars");

    if (!FindAllChars) {
        cerr << "Не удалось найти функцию!" << endl;
        FreeLibrary(load);
        return 1;
    }

    while (true)
    {
        string str;
        string str2;
        cout << "Введите строку: ";
        getline(cin, str);
        cout << "Введите символы для поиска: ";
        getline(cin, str2);

        bool result = FindAllChars(str.c_str(), str2.c_str());
        if (result) {
            cout << "Строка содержит все заданные символы: да" << endl;
        }
        else {
            cout << "Строка не содержит все заданные символы: нет" << endl;
        }
    }

    FreeLibrary(load);
    return 0;
}
