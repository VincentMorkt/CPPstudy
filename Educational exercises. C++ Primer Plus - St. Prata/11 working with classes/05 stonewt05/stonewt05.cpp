// 5. Перепишите класс Stonewt (листинги 11.16 и 11.17) так, чтобы он имел член состояния, который управляет тем, в какой форме интерпретируется объект: стоуны,
// целочисленное значение в фунтах или значение в фунтах с плавающей точкой. Перегрузите операцию << для замены методов show_stn() и show_lbs().
// Перегрузите операции сложения, вычитания и умножения значений Stonewt. Протестируйте полученный класс с помощью короткой программы,
// в которой используются все методы и друзья класса.

// stonewt05.cpp -- определение методов класса Stonewt

#include <iostream>
#include "stonewt05.h"

using std::cout;

stonewt::stonewt(double lbs, Mode form) // конструктор для значения в фунтах
{
    stone = int(lbs) / Lbs_per_stn; // целочисленное деление
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    mode = form;
}

stonewt::stonewt(int stn, double lbs, Mode form) // конструктор для значения в стоунах и фунтах
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    mode = form;
}

stonewt::stonewt() // конструктор по умолчанию
{
    stone = pounds = pds_left = 0;
}

stonewt::~stonewt() {} // деструктор

// перегруженные операторы
stonewt stonewt::operator+(const stonewt &st) const
{
    stonewt add(pounds + st.pounds);   // вычисление происходит методом создания нового объекта, инициализированного результатом вычисления членов pounds
    if (mode == STN || st.mode == STN) // если хотябы один из операндов имел состояние STN, то и результирующий объект будет иметь это состояние
        add.mode = STN;
    return add;
}

stonewt stonewt::operator-(const stonewt &st) const
{
    stonewt diff(pounds + st.pounds);
    if (mode == STN || st.mode == STN)
        diff.mode = STN;
    return diff;
}

stonewt stonewt::operator*(double n) const
{
    stonewt mult(pounds * n);
    if (mode == STN)
        mult.mode = STN;
    return mult;
}

std::ostream &operator<<(std::ostream &os, const stonewt &st) // перегруженная операция << для отображения в формате, указанном в члене состояния
{
    if (st.mode == stonewt::PDS) // в зависимости от состояния отображение будет в формате  pounds или в формате stone, pounds
        os << st.pounds << " pounds";
    else if (st.mode == stonewt::STN)
        os << st.stone << " stone, " << st.pds_left << " pounds";
    return os;
}