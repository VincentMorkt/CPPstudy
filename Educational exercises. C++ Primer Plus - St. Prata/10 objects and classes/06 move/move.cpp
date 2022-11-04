// 6. Пусть имеется следующее объявление класса:
// Создайте определения функций-членов и напишите программу, которая использует этот класс.

// move.cpp -- реализация методов 

#include <iostream>
#include "move.h"

Move::Move(double a, double b) // устанавливает x, y в a, b
{
    x = a;
    y = b;
}

void Move::showmove() const // отображает текущие значения х, у
{
    using std::cout;
    cout << "x = " << x << ", y = " << y << "\n\n";
}

Move Move::add(const Move &m) const
{
    Move n(x + m.x, y + m.y); // объявление и инициализация объекта n класса Move, конструктором, аргументами которого являются выражения суммы
    return n;                 // возврат объекта n
}

void Move::reset(double a, double b) // сбрасывает х, у в а, Ь
{
    x = a;
    y = b;
}