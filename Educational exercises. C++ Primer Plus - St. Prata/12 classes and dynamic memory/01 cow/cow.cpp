// 1. Имеется следующее объявление класса:

// Напишите реализацию для этого класса и короткую программу, использующую все функции-члены.

#include <iostream>
#include <cstring>
#include "cow.h"

using std::cout;
using std::endl;

// методы реализованы с информационными сообщениями об их работе

Cow::Cow() // конструктор по умолчанию
{
    cout << "deaful constructor\n";
    name[0] = '\0';  // первый символ имени - нулевой символ
    hobby = nullptr; // указатель инициализируется нулевым указателем (может быть освобождён delete [])
    weight = 0;
}

Cow::Cow(const char *nm, const char *ho, double wt) // конструктор
{
    cout << "constructor for " << nm << endl;
    strncpy(name, nm, 19); // имя копируется с ограничением на длину символов, оставляя место для нулевого символа
    name[19] = '\0';       // эта строчка необходима на случай, если переданная в аргументе строка превышала 20 символов (вместе с \0)
    // поскольку strncpy не гарантирует, что последним символом будет \0. Если же символов было меньше, в массиве
    // \0 либо будет элементом с индексом 19 (и тогда ничего не поменяется), или встретится раньше, что гарантирует его корректную обработку
    hobby = new char[strlen(ho) + 1]; // создание динамчиеского массива char размером на 1 превышающим длину строки ho (без нулевого символа)
    strcpy(hobby, ho);                // копирование в этот новый массив строки из аргумента
    weight = wt;                      // присваивание веса из аргумента
}

Cow::Cow(const Cow &c) // конструктор копирования
{
    cout << "copy-constructor for " << c.name << endl;
    strcpy(name, c.name);                  // простое копирование имени
    hobby = new char[strlen(c.hobby) + 1]; // создание динамического массива, аналогично предыдущему конструктору
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow() // деструктор
{
    cout << "destructor for " << name << endl;
    delete[] hobby; // освобождение памяти, созданною new. Работает с нулевым указателем
}

Cow &Cow::operator=(const Cow &c) // операция присвоения
{
    cout << "operator= for " << c.name << endl;
    if (this == &c)                        // если объект присваивается сам себе
        return *this;                      // возвращает указатель на объект
    strcpy(name, c.name);                  // копирование имени
    delete[] hobby;                        // освобождение текущей строки
    hobby = new char[strlen(c.hobby) + 1]; // создание новой
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const // метод отображения
{
    cout << endl
         << "show method\n"
         << name << endl
         << "hobby: " << hobby << endl
         << "weight: " << weight << endl
         << endl;
}