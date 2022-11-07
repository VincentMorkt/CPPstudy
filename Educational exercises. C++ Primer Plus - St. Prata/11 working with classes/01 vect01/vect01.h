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
        double mag; // длина вектора
        double ang; // направление вектора в градусах
        Mode mode;  // RECT or POL

        // Закрытые методы установки значений:
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; } // методы, сообщающие значение
        double yval() const { return y; }
        double magval() const { return mag; }
        double angval() const { return ang; }
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