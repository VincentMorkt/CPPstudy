// 4. Перепишите финальный пример класса Time (листинги 11.10, 11.11 и 11.12) так, чтобы все перегруженные операции были реализованы с использованием дружественных функций.

#ifndef MYTIME3_H_
#define MYTIME3_H_

#include <iostream>

class Time // объявление класса
{
private:
    int hours;
    int minutes;

public:
    Time();                           // конструктор по умолчанию
    Time(int h, int m = 0);           // конструктор
    void AddMin(int m);               // добавить минуты
    void AddHr(int h);                // добавить часы
    void Reset(int h = 0, int m = 0); // сброс (до указанных операторов или по умолчанию до нуля)

    // друзья - перегруженные операции
    friend Time operator+(const Time &t1, const Time &t2);
    friend Time operator-(const Time &t1, const Time &t2);
    friend Time operator*(const Time &t, double mult);
    friend Time operator*(double n, const Time &t) { return t * n; } // встроенная функция, использующая предыдущую функцию умножения
    friend std::ostream &operator<<(std::ostream &os, const Time &); // функция вывода, использующая объект ostream
};
#endif