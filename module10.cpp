#include "h10.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>

void ListWork7() {
    List L; //создаем односвязный список Л
    int n;
    std::cout << "Введите 10 чисел:\n";
    for (int i = 0; i < 10; i++) {
        std::cin >> n;
        L.Add(n);
    }
    int op;
    do {
        std::cout << "\nТекущий список: ";
        L.Show();

        std::cout << "\n1. Поиск элемента\n";
        std::cout << "2. Удаление первого элемента\n";
        std::cout << "3. Решение задачи\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите операцию: ";
        std::cin >> op;
        switch (op) {
            case 1: {
                int value;
                std::cout << "Введите значение для поиска: ";
                std::cin >> value;
                if (L.Find(value)) {
                    std::cout << "Элемент найден\n";
                }
                else {
                    std::cout << "Элемент не найден\n";
                }
                break;
            }
            case 2: {
                L.Delete();
                std::cout << "Первый элемент удален\n";
                break;
            }
            case 3: {
                L.Print8();
                break;
            }
        }
    } while (op != 0);
}

void ListWork24() {
    List L;
    int n;
    std::cout << "Введите 10 чисел:\n";
    for (int i = 0; i < 10; i++) {
        std::cin >> n;
        L.Add(n);
    }
    std::cout << "Список:\n";

    L.Show();
    int M;
    std::cout << "Введите значение М чтобы вставлять его после каждого 4го эл-та:\n";
    std::cin >> M;

    int op;
    do {
        std::cout << "\nТекущий список: ";
        L.Show();
        
        std::cout << "\n1. Поиск элемента\n";
        std::cout << "2. Удаление первого элемента\n";
        std::cout << "3. Решение задачи (вставка M после каждого 4-го)\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите операцию: ";
        std::cin >> op;
        switch (op) {
            case 1: {
                int value;
                std::cout << "Введите значение для поиска: ";
                std::cin >> value;
                if (L.Find(value)) {
                    std::cout << "Элемент найден\n";
                }
                else {
                    std::cout << "Элемент не найден\n";
                }
                break;
            }
            case 2: {
                L.Delete();
                std::cout << "Первый элемент удален\n";
                break;
            }
            case 3: {
                L.printListWork24(M);
                std::cout << "Операция выполнена\n";
                break;
            }
        }
    } while (op != 0);
    Node* P2 = L.GetLastNode();
    std::cout << "Ссылка на последний элемент P2: " << P2 << std::endl;
    std::cout << "Значение последнего элемента: " << P2->x << std::endl;
}

void ListWork61() {
    std::ifstream fin("a.txt");
    if (!fin) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return;
    }
    int N;
    fin >> N;
    List L;
    for (int i = 0; i < N; i++) {
        int value;
        fin >> value;
        L.AddSorted(value); // вставка с сортировкой
    }
    fin.close();
    std::cout << "Упорядоченный список:\n";
    L.Show();
    
    int op;
    do {
        std::cout << "\nТекущий список: ";
        L.Show();

        std::cout << "\n1. Поиск элемента\n";
        std::cout << "2. Удаление первого элемента\n";
        std::cout << "3. Решение задачи\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите операцию: ";
        std::cin >> op;
        switch (op) {
            case 1: {
                int value;
                std::cout << "Введите значение для поиска: ";
                std::cin >> value;
                if (L.Find(value)) {
                    std::cout << "Элемент найден\n";
                } else {
                    std::cout << "Элемент не найден\n";
                }
                break;
            }
            case 2: {
                L.Delete();
                std::cout << "Первый элемент удален\n";
                L.Show();
                break;
            }
            case 3: {
                int value;
                std::cout << "Введите значение для вставки в отсортированный список: ";
                std::cin >> value;
                L.AddSorted(value);
                std::cout << "Элемент вставлен\n";
                break;
            }
        }
    } while (op != 0);
    std::cout << "Итоговый список:\n";
    L.Show();
}

//----------------------------------------------------------

void Dynamic9() {
    Stack s1;
    Stack s2;

    s1.push(6);
    s1.push(8);
    s1.push(3);
    s1.push(5);
    s1.push(7);

    s2.push(2);
    s2.push(4);

    int op;
    do {
        std::cout << "\nСтек 1: ";
        s1.print();
        std::cout << "Стек 2: ";
        s2.print();

        std::cout << "\n1. Поиск элемента\n";
        std::cout << "2. Удаление элемента\n";
        std::cout << "3. Решение задачи\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите операцию: ";
        std::cin >> op;
        switch (op) {
            case 1: {
                int value;
                std::cout << "Введите значение для поиска: ";
                std::cin >> value;
                if (s1.find(value)) {
                    std::cout << "Элемент найден\n";
                }
                else {
                    std::cout << "Элемент не найден\n";
                }
                break;
            }
            case 2: {
                int x;
                if (s1.pop(x)) {
                    std::cout << "Удален элемент: " << x << std::endl;
                }
                else {
                    std::cout << "Стек пуст\n";
                }
                break;
            }
            case 3: {
                s1.moveTo(s2);
                break;
            }
        }
    } while (op != 0);
}

//-----------------------------------------------

void Dynamic18() {
    Queue q;

    // создание очереди
    q.push(5);
    q.push(8);
    q.push(3);

    int op;
    do {
        std::cout << "\nОчередь: ";
        q.print();

        std::cout << "1. Удаление элемента\n";
        std::cout << "2. Решение задачи\n";
        std::cout << "0. Назад\n";
        std::cout << "Выберите операцию: ";
        std::cin >> op;
        switch (op) {
            case 1: {
                int removed;
                if (q.pop(removed)) {
                    std::cout << "Удален элемент: " << removed << std::endl;
                }
                else {
                    std::cout << "Очередь пуста\n";
                }
                break;
            }
            case 2: {
                int D;
                std::cout << "Введите значение D: ";
                std::cin >> D;
                q.solve(D);
                break;
            }
        }
    } while (op != 0);
}