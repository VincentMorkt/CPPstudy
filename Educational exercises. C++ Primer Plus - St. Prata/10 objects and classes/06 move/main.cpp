// 6. Пусть имеется следующее объявление класса:
// Создайте определения функций-членов и напишите программу, которая использует этот класс.

// main.cpp -- программа демонстратор

#include <iostream>
#include "move.h"

int main()
{
    using namespace std;

    cout << "Move move1;\n"; // конструктор по умолчанию
    Move move1;
    cout << "move1.showmove();:\n";
    move1.showmove();

    cout << "Move move2(34.3, 12.1);\n"; // конструктор с инициализацией
    Move move2(34.3, 12.1);
    cout << "move2.showmove();:\n";
    move2.showmove();

    cout << "Move move3(10, 10);\n"; // конструктор с инициализацией
    Move move3(10, 10);
    cout << "move3.showmove();:\n";
    move3.showmove();

    cout << "move1 = move2.add(move3);"; // метод add
    move1 = move2.add(move3);            // вызов метода add и присвоение возвращаемого значения
    cout << "move1.showmove();:\n";
    move1.showmove();

    cout << "move1.reset(1,1);\n"; // метод reset
    move1.reset(1, 1);
    cout << "move1.showmove();:\n";
    move1.showmove();

    cin.get();
    return 0;
}