// 4. Имеется следующий вариант класса Stack, определенного в листинге 10.10:
// Как понятно из закрытых членов, данный класс использует динамически выделенный массив для хранения элементов стека.
// Перепишите методы для соответствия новому представлению и напишите программу, которая демонстрирует работу
// всех методов, включая конструктор копирования и операцию присваивания.

// main.cpp -- программа демонстратор класса Stuck

#include <iostream>
#include <cctype>
#include "stack.h"

int main() 
{
    using namespace std;

    char ch;
    int size;
    unsigned long po = 10;

    Stack st1;
    cout << "st1.push(po); po = " << po << endl;
    st1.push(po);
    po = 20;

    Stack st2(st1);
    Stack st3 = st2;

    cout << "Stack st2(st1);\n"
         << "Stack st3 = st2;\n";
    st3.push(po);
    cout << "st3.push(po); po = " << po << endl;
    st3.pop(po);
    st3.pop(po);
    cout << "st3.pop(po);\n"
         << "st3.pop(po); po = " << po << endl; // должно отобразить 10

    cin.get();
    return 0;
}