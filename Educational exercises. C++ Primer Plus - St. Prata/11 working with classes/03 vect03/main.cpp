// 3. Модифицируйте код в листинге 11.15 так, чтобы вместо сообщений о результатах одиночной попытки при конкретной комбинации расстояние/шаг
// сообщалось максимальное, минимальное и среднее количество шагов для N попыток, где N - целое число, вводимое пользователем.

// main.cpp -- испоьзование класса Vector

#include <iostream>
#include <cstdlib> // прототипы rand(), srand()
#include <ctime>   // time()
#include <climits> // INT_MAX
#include "vect03.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));

    double target; // целевое расстояние
    double dstep;  // длина шага
    int cycles;    // количество циклов

    cout << "Enter target distance (q to quit): "; // ввод целевого расстояния
    while (cin >> target)                          // пока ввод успешен
    {
        srand(time(0));
        double direction;                   // угол
        unsigned long long stepsSUM = 0;    // сумма для подсчёта статистики (каждый новый цикл значения обнуляются(пересоздаются объекты))
        unsigned long minSteps = ULONG_MAX; // минимальное количество шагов (взято максимальное значение, чтобы любое другое обновило его)
        unsigned long maxSteps = 0;         // максимальное количество шагов

        cout << "Enter step lenght: ";          // ввод длины шага
        if (!(cin >> dstep))                    // если ввод не успешен
            break;                              // прервать
        cout << "Enter the number of cycles: "; // ввод количества циклов для сбора статистики
        if (!(cin >> cycles))                   // если ввод не успешен
            break;                              // прервать

        for (int i = 0; i < cycles; i++)
        {
            unsigned long steps = 0; // количество шагов (каждый новый цикл значения обнуляются(пересоздаются объекты))
            Vector step;             // вектор кажого шага
            Vector result(0.0, 0.0); // суммарный вектор

            while (result.magval() < target) // пока длина суммарного вектора меньше целевого расстояния
            {
                direction = rand() % 360;                  // угол = рандом() % 360
                step.reset(dstep, direction, Vector::POL); // метод .reset, задающий значения в соответствии с длиной шага, углом и устанавливающий mode в POL
                result = result + step;                    // суммирование векторов
                steps++;                                   // подсчёт количества шагов
            }
            minSteps = (steps < minSteps) ? steps : minSteps; // если steps меньше, чем сохранённое в minSteps ранее минимальное количество шагов - значение обновляется
            maxSteps = (steps > maxSteps) ? steps : maxSteps; // то же самое для maxSteps
            stepsSUM += steps;                                // подсчёт всех шагов для последующего нахождения среднего значения
        }
        cout << "For " << cycles << " cycles, target distance is " << target << " was reached in steps size of " << dstep << endl
             << "average: of " << stepsSUM / cycles << " steps;\n"
             << "    min: of " << minSteps << " steps;\n"
             << "    max: of " << maxSteps << " steps;\n\n"
             << "Enter target distance (q to quit): "; // ввод целевого расстояния
    }
}