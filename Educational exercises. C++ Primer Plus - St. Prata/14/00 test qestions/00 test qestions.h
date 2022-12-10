// 1. Для каждого набора классов из столбца А укажите, какое наследование -
// общедоступное или закрытое - лучше подходит для столбца Б.

// А                                                           Б
// class Bear (Медведь)                                        class PolarBear (Белый медведь)  -- является, открытое наследование
// class Kitchen (Кухня)                                       class Ноте (Дом)                 -- содержит, закрытое наследование или включение
// class Person (Человек)                                      class Programmer (Программист)   -- является, открытое наследование
// class Person (Человек)                                      class HorseAndJockey (Лошадь и жокей) -- содержит, закрытое наследование или включение
// class Person, class Automobile (Человек, Автомобиль)        class Drive (Поездка)            -- содержит, множественное закрытое наследование или включение

// 2. Пусть имеются следующие определения:
#include <iostream>
#include <cstring>

// class Frabjous
// {
// private:
//     char fab[20];

// public:
//     Frabjous(const char *s = "С++ ") /*: fab(s)*/ { strcpy(fab, s); } // Стив, что за приколы?
//     virtual void tell() { std::cout << fab; }
// };
// class Gloam
// {
// private:
//     int glip;
//     Frabjous fb;
// public:
//     Gloam(int g = 0, const char *s = "С++") : glip(g), fb(s) {}
//     Gloam(int g, const Frabjous &f) : glip(g), fb(f) {}
//     void tell();
// };

// void Gloam::tell()
// {
//    std::cout << glip << ", ";
//    Frabjous::tell();
// }

// Напишите определения для трех методов класса Gloam,
// если функция tell() из класса Gloam выводит значения glip и fb.

// 3. Пусть имеются следующие определения

class Frabjous
{
private:
    char fab[20];

public:
    Frabjous(const char *s = "С++ ") /*: fab(s)*/ { strcpy(fab, s); }
    virtual void tell() { std::cout << fab; }
};

class Gloam : private Frabjous
{
private:
    int glip;

public:
    Gloam(int g = 0, const char *s = "С++") : glip(g), Frabjous(s) {}
    Gloam(int g, const Frabjous &f) : glip(g), Frabjous(f) {}
    void tell();
};

void Gloam::tell()
{
    std::cout << glip << ", ";
    Frabjous::tell();
}

// Напишите определения для трех методов класса Gloam,
// если функция tell() из класса Gloam выводит значения glip и fb.

// 4. Пусть имеется следующее определение, основанное на шаблоне Stack из листинга 14.13
// и на классе Worker из листинга 14.10:
// Stack<Worker *> sw;
// Напишите объявление класса, который будет сгенерирован
// (только объявление, без встроенных методов).
// class Stack<Worker *>
// {
// private:
//     enum
//     {
//         MAX = 10
//     };
//     Worker *items[MAX];
//     int top;

// public:
//     Stack();
//     bool isempy();
//     bool isfull();
//     bool push(const Worker *&item);
//     bool pop(Worker *&item);
// };

// 5. Воспользуйтесь определениями шаблонов, рассмотренных в этой главе, чтобы определить:
// • массив объектов string;
// ArrayTP<string> arrString;
// • стек массивов значений double;
// StackTP<Array<double>> stackArrDouble;
// • массив стеков указателей на объекты Worker.
// ArrayTP<StackTP<Worker *>> arrStackWorker;
// Сколько определений шаблонов классов сгенерировано в листинге 14.18?

// 6. Объясните разницу между виртуальными и невиртуальными базовыми классами.
// Виртуальные базовые классы позволяют создавать цепочки наследования с множественными
// наследованиями от базового класса, при которых будет создан только один экземпляр объекта
// базового виртуальнго класса.
