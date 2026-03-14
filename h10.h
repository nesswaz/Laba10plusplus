#include <vector>
#include <string>
#pragma once
#include <iostream>

struct Node {
    int x;
    Node* Next;
};

class List {

private:
    Node* Head;
    Node* Last;
public:
    List() { // конструктор по умолчанию
        Head = nullptr;
        Last = nullptr;
    }

    List(const List& other) {    // конструктор копирования
        Head = nullptr;
        Last = nullptr;
        Node* temp = other.Head;
        while (temp != nullptr) {
            Add(temp->x);
            temp = temp->Next;
        }
    }

    ~List() { // деструктор
        while (Head != nullptr) {
            Node* temp = Head;
            Head = Head->Next;
            delete temp;
        }
    }
    
    void Add(int data) {// добавление элемента
        Node* Temp; //создаем указатель
        if (Head == nullptr) { //если список еще пустой
            Head = new Node; //создаем новый элемент в памяти
            Last = Head;
            Head->Next = nullptr; 
        }
        else {
            Temp = new Node; //если эл-т не первый, создаем память под новый элемент
            Last->Next = Temp; //переставляем указатель на следующий эл-т
            Last = Temp; 
            Last->Next = nullptr; //послед. эл-т начинает указывать на новый
        }
        Last->x = data; //записываем значение 
    }

    void Delete() { // удаление первого элемента
        if (Head != nullptr) {
            Node* temp = Head;
            Head = Head->Next; //передвигаем голову 
            delete temp; //удаляем предыдущий эл-т (первый)
        }
    }

    bool Find(int value) {// поиск элемента
        Node* temp = Head;
        while (temp != nullptr) {
            if (temp->x == value)
                return true;
            temp = temp->Next;
        }
        return false;
    }

    void Show() {// вывод списка
        Node* temp = Head; //создаем указатель на начало списка
        while (temp != nullptr) { //пока эл-ты существуют цикл
            std::cout << temp->x << " "; //выводим в консоль значения
            temp = temp->Next; //переход к следщ. эл-ту
        }
        std::cout << std::endl;
    }
    
    void Print8() {// задача варианта — указатель на 8 элемент
        Node* temp = Head;
        for (int i = 1; i < 8; i++) {
            temp = temp->Next;
        }
        std::cout << "Указатель на 8 эл-те: " << temp << std::endl;
        std::cout << "Значение 8 эл-та: " << temp->x << std::endl;
    }

    void printListWork24(int M) {
        Node* temp = Head;
        int count = 1; // считаем элементы начиная с 1-го
        while (temp != nullptr) {
            if (count % 4 == 0) {
                Node* newNode = new Node; //создаем новый эл-т списка
                newNode->x = M;
                newNode->Next = temp->Next;
                temp->Next = newNode; //текущий эл-т указывает на новый

                if (temp == Last) Last = newNode; // обновляем Last (последний эл-т)

                temp = newNode; // пропускаем вставленный
            }
            temp = temp->Next; // переход к следующему элементу
            count++;
        }
    }
    Node* GetLastNode() {
        if (!Head) return nullptr;  // список пустой
        Node* temp = Head;
        while (temp->Next != nullptr) {  // идём пока есть следующий элемент
            temp = temp->Next;
        }
        return temp; // последний узел
    }
    void AddSorted(int value) {
        Node* newNode = new Node; 
        newNode->x = value;
        newNode->Next = nullptr;
        if (!Head || value < Head->x) { // если список пустой или элемент меньше значения головы
            newNode->Next = Head;
            Head = newNode;
            return;
        }
        Node* temp = Head; // ищем место для вставки
        while (temp->Next && temp->Next->x < value) { //следщ. эл-т меньше value
            temp = temp->Next;
        }
        newNode->Next = temp->Next; //вставляем эл-т
        temp->Next = newNode;
    }
};

void ListWork7();
void ListWork24();
void ListWork61();


//----------------------------------------------------------

class Stack 
{
private:
    struct PNode {
        int Data;
        PNode* Next;
    };
    PNode* top;
public:
    Stack() {// Конструктор по умолчанию
        top = nullptr;
    }
    
    Stack(const Stack& other) {// Конструктор копирования
        top = nullptr;
        if (other.top == nullptr) {
            return;
        }
        PNode* src = other.top;
        PNode* newTop = nullptr;
        PNode* last = nullptr;

        while (src) {
            PNode* node = new PNode;
            node->Data = src->Data;
            node->Next = nullptr;

            if (newTop == nullptr) {
                newTop = node;
            }
            else {
                last->Next = node;
            }
            last = node;
            src = src->Next;
        }
        top = newTop;
    }

    ~Stack() { // Деструктор
        while (top) {
            PNode* temp = top;
            top = top->Next;
            delete temp;
        }
    }
    
    void push(int x) {// Добавление элемента
        PNode* node = new PNode;
        node->Data = x;
        node->Next = top;
        top = node;
    }

    bool pop(int& x) {// Удаление элемента
        if (top == nullptr) {
            return false;
        }
        PNode* temp = top;
        x = top->Data;
        top = top->Next;
        delete temp;
        return true;
    }

    bool find(int x) { // Поиск
        PNode* p = top;
        while (p) {
            if (p->Data == x) {
                return true;
            }
            p = p->Next;
        }
        return false;
    }

    void print() { // Печать стека
        PNode* p = top;
        while (p) {
            std::cout << p->Data << " ";
            p = p->Next;
        }
        std::cout << std::endl;
    }

    void moveTo(Stack& s2) { // Решение задачи
        while (top != nullptr && top->Data % 2 != 0) { //пока не последний и пока эл-т нечетный
            PNode* temp = top; //вырезаем этот элемент
            top = top->Next;
            temp->Next = s2.top; //вставляем его во второй стек
            s2.top = temp;
        }
        std::cout << "Новый адрес Р1: " << top << std::endl;
        std::cout << "Новый адрес Р2: " << s2.top << std::endl;
    }
};

void Dynamic9();    

//-------------------------------------------------------------------------

class Queue
{
private:
    struct PNode {
        int Data;
        PNode* Next;
    };

    PNode* head; // P1
    PNode* tail; // P2

public: 
    Queue()// Конструктор по умолчанию
    {
        head = nullptr;
        tail = nullptr;
    }

    ~Queue() {// Деструктор
        while (head)
        {
            PNode* temp = head;
            head = head->Next;
            delete temp;
        }
    }

    // Добавление в конец очереди
    void push(int x) {
        PNode* node = new PNode;
        node->Data = x;
        node->Next = nullptr;
        if (tail == nullptr) {
            head = tail = node;
        }
        else {
            tail->Next = node;
            tail = node;
        }
    }
   
    bool pop(int&value) { // Удаление из начала
        if (head == nullptr) {
            return false;
        }
        PNode* temp = head;
        value = head->Data;
        head = head->Next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
        return true;
    }

    void print() {// Вывод очереди
        PNode* p = head;
        while (p) {
            std::cout << p->Data << " ";
            p = p->Next;
        }
        std::cout << std::endl;
    }

    void solve(int D) { // Решение задачи
        push(D);// добавить D в конец
        int removed;
        if(pop(removed)) { // извлечь первый элемент
            std::cout << "Значение извлеченного элемента: " << removed << std::endl;
        }
        std::cout << "Индекс (с 1.) - Значение извлеченного эл-та: " << removed << std::endl;
        std::cout << "Новый P1 (начало): " << head << std::endl;
        std::cout << "Новый P2 (конец): " << tail << std::endl;
    }
};

void Dynamic18();