// 1. Модифицирyйте код в листинге 11.15 так, чтобы обеспечить запись в файл последовательных позиций при слyчайном блyждании. Каждая позиция должна помечаться номером шага.
// Также программа должна записывать в файл начальные yсловия (целевое расстояние и длинy шага) и сyммарные резyльтаты.
// Содержимое файла может выглядеть примерно так:

// Target Distance: 100, Step Size: 20
// 0: (x, y) (0, 0)
// 1: (x, y) (-11.4715, 16.383)
// 2: (x, y) (-8.68807, -3.42232)
// ...
// 26: (x, y) = (42.2919, -78.2594)
// 27: (x, y) = (58.6749, -89.7309)

// After 27 steps , the subj ect has the following location:
// (x, y) =  (58.6749, -89.7309)
// or
// (m, a) = (107.212, -56.8194)

// Average outward dis tance per step = 3.97081

// main.cpp -- испоьзование класса Vector

#include <iostream>
#include <fstream>
#include <cstdlib> // прототипы rand(), srand()
#include <ctime>   // time()
#include "vect01.h"

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
    ofstream fout;
    fout.open("vect01.txt");

    cout << "Enter target distance (q to quit): "; // ввод целевого расстояния
    while (cin >> target)                          // пока ввод успешен
    {
        cout << "Enter step lenght: "; // ввод длины шага
        if (!(cin >> dstep))           // если ввод не успешен
            break;                     // прервать

        cout << "\nTarget Distance: " << target << ", Step Size: " << dstep << endl // вывод информации о начальных параметрах на консоль
             << endl
             << steps << ": (x, y) = (" << result.xval() << " ," << result.yval() << ")\n"; // первая строчка информации о шаге и значении вектора

        fout << "\nTarget Distance: " << target << ", Step Size: " << dstep << endl // вывод информации о начальных параметрах в файл
             << endl;

        while (result.magval() < target) // пока длина суммарного вектора меньше целевого расстояния
        {
            // Target Distance: 100, Step Size: 20
            // 0: (x, y) (0, 0)
            direction = rand() % 360;                  // угол = рандом() % 360
            step.reset(dstep, direction, Vector::POL); // метод .reset, задающий значения в соответствии с длиной шага, углом и устанавливающий mode в POL
            result = result + step;                    // суммирование векторов
            steps++;                                   // подсчёт количества шагов
            cout << steps << ": (x, y) = (" << result.xval() << ", " << result.yval() << ")\n";
        }

        cout << "\nAfter " << steps << " steps, the subject has the following location: \n" // вывод результатов в формате RECT
             << result << endl;
        fout << "After " << steps << " steps, the subject has the following location: \n" // то же самое в файл
             << result << endl;
        result.polar_mode();                                                                  // переключение формата
        cout << "or\n"                                                                        // или
             << result                                                                        // вывод результатов в формате PO
             << "\n\nAverage outward distance per step = " << result.magval() / steps << endl // вывод расстояния/шаг
             << endl;
        fout << "or\n"
             << result
             << "\n\nAverage outward distance per step = " << result.magval() / steps << endl // то же самое в файл
             << endl;

        steps = 0;                                     // сброс счётчика шагов
        result.reset(0.0, 0.0);                        // сброс суммы векторов
        cout << "Enter target distance (q to quit): "; // ввод целевого расстояния
    }
}