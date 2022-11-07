// 2. Модифицируйте заголовок класса Vector и файлы реализации (листинги 11.13 и 11.14) так, чтобы модуль и направление вектора больше не хранились в виде компонентов данных.
// Вместо этого они должны вычисляться по требованию при вызове методов magval() и angval(). Вы должны оставить открытый интерфейс без изменений
// (те же открытые методы с теми же аргументами), но изменить закрытую часть, включая некоторые из закрытых методов и их реализации.
// Протестируйте модифицированную версию с помощью программы из листинга 11.15, которая должна остаться неизменной, поскольку открытый интерфейс класса Vector не менялся.

// vect02.cpp -- реализация методов

#include <cmath>
#include "vect02.h" // включает <iosteam>
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
    // void Vector::set_mag() // вычисляет модуль из x и y
    // {
    //     mag = sqrt(x * x + y * y);
    // }

    // void Vector::set_ang()
    // {
    //     if (x == 0.0 && y == 0.0)
    //         ang = 0.0;
    //     else
    //         ang = atan2(y, x);
    // }

    // void Vector::set_x() // устанавливает x по полярным координатам
    // {
    //     x = mag * cos(ang);
    // }

    // void Vector::set_y() // устанавливает y по полярным координатам
    // {
    //     y = mag * sin(ang);
    // }

    // открытые методы
    Vector::Vector() // конструктор по умолчанию
    {
        x = y = /* mag = ang =*/0.0;
        mode = RECT;
    }
    Vector::Vector(double n1, double n2, Mode form) // конструирует вектор по прямоугольным координатам, если form == RECT (по умолчанию)
    {                                               // или по полярным координатам, если form == POL
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            // set_mag();
            // set_ang();
        }
        else if (form == POL)
        {
            // mag = n1;
            // ang = n2 / Rad_to_deg;
            // set_x();
            // set_y();
            x = n1 * cos(n2);
            y = n1 * sin(n2 / Rad_to_deg);
        }
        else // некорректный третий аргумент Vector(), вектор устанавливается в 0
        {
            cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
            x = y = /* mag = ang =*/0.0;
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
            // set_mag();
            // set_ang();
        }
        else if (form == POL)
        {
            // mag = n1;
            // ang = n2 / Rad_to_deg;
            // set_x();
            // set_y();
            x = n1 * cos(n2);
            y = n1 * sin(n2 / Rad_to_deg);
        }
        else // некорректный третий аргумент Vector(), вектор устанавливается в 0
        {
            cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
            x = y = /* mag = ang =*/0.0;
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

    double Vector::magval() const /*{ return mag; }*/
    {
        return sqrt(x * x + y * y);
    }

    double Vector::angval() const /*{ return ang; }*/
    {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);
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
            os << "(m, a) = (" << sqrt(v.x * v.x + v.y * v.y) /*v.mag*/ << ", ";
            if (v.x == 0.0 && v.y == 0.0)
                os << 0.0 << ")";
            else
                os << /*v.ang*/ atan2(v.y, v.x) * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid"; // недопустимый режим объекта Vector
        return os;
    }

} // конец пространства имён VECTOR
