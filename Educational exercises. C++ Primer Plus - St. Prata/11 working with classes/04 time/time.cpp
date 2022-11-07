// 4. Перепишите финальный пример класса Time (листинги 11.10, 11.11 и 11.12) так, чтобы все перегруженные операции были реализованы с использованием дружественных функций.

// time.cpp -- реализация методов класса Time

#include "time.h"

Time::Time() // конструктор по умолчанию
{
    hours = minutes = 0;
}

Time::Time(int h, int m) // конструктор
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) // добавить минуты
{
    minutes += m;
    hours += minutes / 60; 
    minutes %= 60;
}

void Time::AddHr(int h) // добависть часы
{
    hours += h;
}

void Time::Reset(int h, int m) // сброс
{
    hours = h;
    minutes = m;
}

Time operator+(const Time &t1, const Time &t2) // перегруженные операции
{
    Time sum;
    sum.minutes = t1.minutes + t2.minutes;
    sum.hours = t1.hours + t2.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
Time operator-(const Time &t1, const Time &t2)
{
    Time diff;
    int tot1, tot2;
    tot1 = t2.minutes + 60 * t2.hours;
    tot2 = t1.minutes + 60 * t1.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time operator*(const Time &t, double mult)
{
    Time result;
    long tottalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = tottalminutes / 60;
    result.minutes = tottalminutes % 60;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}