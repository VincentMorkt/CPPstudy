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

// vect.cpp -- реализация методов

#include <cmath>
#include "vect01.h" // включает <iosteam>
using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR // объявление пространства имён
{
    const double Rad_to_deg = 45.0 / atan(1.0); // вычисляет количество градусов в одном радиане

    // Закрытые методы установки значений:
    void Vector::set_mag() // вычисляет модуль из x и y
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        if (x == 0.0 && y == 0.0)
            ang = 0.0;
        else
            ang = atan2(y, x);
    }

    void Vector::set_x() // устанавливает x по полярным координатам
    {
        x = mag * cos(ang);
    }

    void Vector::set_y() // устанавливает y по полярным координатам
    {
        y = mag * sin(ang);
    }

    // открытые методы
    Vector::Vector() // конструктор по умолчанию
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    Vector::Vector(double n1, double n2, Mode form) // конструирует вектор по прямоугольным координатам, если form == RECT (по умолчанию)
    {                                               // или по полярным координатам, если form == POL
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else // некорректный третий аргумент Vector(), вектор устанавливается в 0
        {
            cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form) // устанавливает вектор по прямоугольным координатам, если form == RECT (по умолчанию)
    {                                                   // или по полярным координатам, если form == POL
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        }
        else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        }
        else // некорректный третий аргумент Vector(), вектор устанавливается в 0
        {
            cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }

    Vector::~Vector(){}; // деструктор

    void Vector::polar_mode() // установка режима POL
    {
        mode = POL;
    }
    void Vector::rect_mode() // установка режима RECT
    {
        mode = RECT;
    }

    // перегрузка операций
    Vector Vector::operator+(const Vector &b) const // слозение векторов
    {
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector &b) const // вычитание вектора b из a
    {
        return Vector(x - b.x, y - b.y);
    }
    Vector Vector::operator-() const // смена знака вектора на противоположный
    {
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const // умножение вектора на n
    {
        return Vector(n * x, n * y);
    }

    // друзья
    Vector operator*(double n, const Vector &a) // усножает n на вектор
    {
        return a * n;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &v) // отображает координаты в соответствии с mode
    {
        if (v.mode == Vector::RECT)
            os << "(x, y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m, a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid"; // недопустимый режим объекта Vector
        return os;
    }
} // конец пространства имён VECTOR
