#include <iostream>
#include "h10.h"
#ifdef _WIN64
#include <windows.h>
#endif
int main() {
    using namespace std;
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif
    int choice;
    do {
        cout << "\nСписок задач:\n";
        cout << "1. Dynamic9" << endl;
        cout << "2. Dynamic18" << endl;
        cout << "3. ListWork7" << endl;
        cout << "4. ListWork24" << endl;
        cout << "5. ListWork61" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                Dynamic9();
                break;
            }
            case 2: {
                Dynamic18();
                break;
            }
            case 3: {
                ListWork7();
                break;
            }
            case 4: {
                ListWork24();
                break;
            }
            case 5: {
                ListWork61();
                break;
            }
            case 0: {
                cout << "Выход из программы\n";
                break;
            }
            default:
                cout << "Введено неверный пункт\n";
        }
    } 
    while (choice != 0);
    return 0;
}