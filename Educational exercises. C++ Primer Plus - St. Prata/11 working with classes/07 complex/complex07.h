// 7. Комплексное число состоит из двух частей - вещественной и мнимой. Один из способов записи такого числа выглядит как (3.0, 4.0) . Здесь 3.0 - вещественная часть, а 4.0 - мнимая.
// Предположим, что а = (А, Bi) и с = (С, Di). Ниже представлены некоторые операции с комплексными числами:

// • сложение: а + с = (А + С, (В + D)i)
// • вычитание: а - с = (А - С, (В - D)i)
// • умножение: а * с = (А * С - B * D, (A * D + B * C)i)
// • умножение (х - вещественное число): х * с = (х * С, x * Di)
// • сопряжение: -а = (А, - Bi)

// Определите класс complex так, чтобы следующая программа могла использовать его с корректными результатами:
#ifndef COMPLEX07_H_
#define COMPLEX07_H_

class complex
{
private:
    double N;
    double I;

public:
    complex();                                 // конструктор по умолчанию
    complex(double x, double i);               // конструктор
    complex operator+(const complex &C) const; // перегруженные операции
    complex operator-(const complex &C) const;
    complex operator-() const;
    complex operator*(const complex &C) const;
    complex operator*(double n) const;
    friend complex operator*(double n, const complex &C) { return C * n; } // встроенная функция
    friend std::ostream &operator<<(std::ostream &os, const complex &C);   // дружественные функции ввода-вывода
    friend std::istream &operator>>(std::istream &is, complex &C);         // с перегруженными операторами
};

complex::complex()
{
    N = I = 0;
}

complex::complex(double x, double y)
{
    N = x;
    I = y;
}

complex complex::operator+(const complex &C) const
{
    complex sum(N + C.N, I + I);
    return sum;
}

complex complex::operator-(const complex &C) const
{
    complex diff(N - C.N, I - C.I);
    return diff;
}

complex complex::operator-() const
{
    complex conj(N, -I);
    return conj;
}

complex complex::operator*(const complex &C) const
{
    complex mult(N * C.N - I * C.I, N * C.I + I * C.N);
    return mult;
}

complex complex::operator*(double n) const
{
    complex mult(N * n, I * n);
    return mult;
}

std::ostream &operator<<(std::ostream &os, const complex &C)
{
    os << "(" << C.N << ", " << C.I << "i)";
    return os;
}

std::istream &operator>>(std::istream &is, complex &C)
{
    using std::cout;

    cout << "real: ";
    if (!(is >> C.N))
        return is;
    cout << "imaginary: ";
    is >> C.I;
    return is;
}

#endif