// 2. Модифицируйте заголовок класса Vector и файлы реализации (листинги 11.13 и 11.14) так, чтобы модуль и направление вектора больше не хранились в виде компонентов данных. 
// Вместо этого они должны вычисляться по требованию при вызове методов magval() и angval(). Вы должны оставить открытый интерфейс без изменений 
// (те же открытые методы с теми же аргументами), но изменить закрытую часть, включая некоторые из закрытых методов и их реализации.
// Протестируйте модифицированную версию с помощью программы из листинга 11.15, которая должна остаться неизменной, поскольку открытый интерфейс класса Vector не менялся.

// main.cpp -- испоьзование класса Vector

#include <iostream>
#include <cstdlib> // прототипы rand(), srand()
#include <ctime>   // time()
#include "vect02.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));

    double direction;        // угол
    Vector step;             // вектор кажого шага
    Vector result(0.0, 0.0); // суммарный вектор
    unsigned long steps = 0; // количество шагов
    double target;           // целевое расстояние
    double dstep;            // длина шага

    cout << "Enter target distance (q to quit): "; // ввод целевого расстояния
    while (cin >> target)                          // пока ввод успешен
    {
        cout << "Enter step lenght: ";   // ввод длины шага
        if (!(cin >> dstep))             // если ввод не успешен
            break;                       // прервать
        while (result.magval() < target) // пока длина суммарного вектора меньше целевого расстояния
        {
            direction = rand() % 360;                  // угол = рандом() % 360
            step.reset(dstep, direction, Vector::POL); // метод .reset, задающий значения в соответствии с длиной шага, углом и устанавливающий mode в POL
            result = result + step;                    // суммирование векторов
            steps++;                                   // подсчёт количества шагов
        }
        cout << "After " << steps << " steps, the subject has the following location: \n"
             << result << endl;                                                            // вывод результатов в формате RECT
        result.polar_mode();                                                               // переключение формата
        cout << "or\n"                                                                    // или
             << result << endl;                                                            // вывод результатов в формате POL
        cout << "Average outward distance per step = " << result.magval() / steps << endl; // вывод расстояния/шаг
        steps = 0;                                                                         // сброс счётчика шагов
        result.reset(0.0, 0.0);                                                            // сброс суммы векторов
        cout << "Enter target distance (q to quit): ";                                     // ввод целевого расстояния
    }
}