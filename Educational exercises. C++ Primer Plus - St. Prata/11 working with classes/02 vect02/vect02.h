// 2. Модифицируйте заголовок класса Vector и файлы реализации (листинги 11.13 и 11.14) так, чтобы модуль и направление вектора больше не хранились в виде компонентов данных. 
// Вместо этого они должны вычисляться по требованию при вызове методов magval() и angval(). Вы должны оставить открытый интерфейс без изменений 
// (те же открытые методы с теми же аргументами), но изменить закрытую часть, включая некоторые из закрытых методов и их реализации.
// Протестируйте модифицированную версию с помощью программы из листинга 11.15, которая должна остаться неизменной, поскольку открытый интерфейс класса Vector не менялся.

// vect02.h -- объявление класса Vector

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR // объявление пространства имён
{
    class Vector // объявление класса
    {
    public:
        enum Mode
        {
            RECT,
            POL
        }; // прямоугольные, полярные координаты (константы для метки)

    private:
        double x;   // горизонтальное значение
        double y;   // вертикальное значение
        // double mag; // длина вектора
        // double ang; // направление вектора в градусах
        Mode mode;  // RECT or POL

        // Закрытые методы установки значений:
        // void set_mag();
        // void set_ang();
        // void set_x();
        // void set_y();

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; } // методы, сообщающие значение
        double yval() const { return y; }
        double magval() const; /*{ return mag; }*/
        double angval() const; /*{ return ang; }*/
        void polar_mode(); // установка режима POL/RECT
        void rect_mode();

        // перегрузка операций
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        // друзья
        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    };
} // конец пространства имён VECTOR
#endif