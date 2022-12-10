// 3. Перепишите иерархию классов baseDMA-lacksDMA-hasDMA таким образом, чтобы все три класса были порождены от абстрактного базового класса.
// Протестируйте результат с помощью программы, подобной приведенной в листинге 13.10. То есть она должна использовать массив указателей
// на абстрактный базовый класс и позволять пользователю принимать во время работы программы решения о том, объекты какого типа создавать.
// Добавьте в определения классов виртуальные методы View() для управления выводом данных.

// dma.cpp --dma class methods

#include "dma.h"
#include <cstring>
#include <iostream>

// absDMA methods

absDMA::absDMA(const char *l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

absDMA::absDMA(const absDMA &rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

absDMA::~absDMA() { delete[] label; }

absDMA &absDMA::operator=(const absDMA &rs)
{
    if (this == &rs)
        return *this;
    delete[] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

void absDMA::View()
{
    std::cout << "Label: " << label << std::endl
              << "Rating: " << rating << std::endl;
}

// baseDMA methods

std::istream &operator>>(std::istream &is, baseDMA &rs)
{
    using std::cout;
    cout << "Enter lable: ";
    char label[40];
    is.get(label, 40);
    label[39] = '\0';
    while (is.get() != '\n')
        continue;
    cout << "Enter rating: ";
    int rating;
    while (!(is >> rating))
    {
        cout << "Bad input, try again: ";
        is.clear();
        while (is.get() != '\n')
            continue;
    }
    while (is.get() != '\n')
        continue;
    rs = baseDMA(label, rating);
    return is;
}

void baseDMA::View()
{
    absDMA::View();
}

// lacksDMA methods

lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::istream &operator>>(std::istream &is, lacksDMA &rs)
{
    using std::cout;
    is >> (baseDMA &)rs;
    cout << "Enter color: ";
    is.get(rs.color, 40);
    rs.color[39] = '\0';
    while (is.get() != '\n')
        continue;
    return is;
}

void lacksDMA::View()
{
    baseDMA::View();
    std::cout << "Color: " << color << std::endl;
}

// hasDMA methods
hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs) // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    absDMA::operator=(hs); // copy base portion
    delete[] style;        // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::istream &operator>>(std::istream &is, hasDMA &rs)
{
    using std::cout;
    is >> (baseDMA &)rs;
    cout << "Enter style: ";
    char style_[40];
    is.get(style_, 40);
    style_[39] = '\0';
    while (is.get() != '\n')
        continue;
    delete[] rs.style;
    rs.style = new char[strlen(style_) + 1];
    strcpy(rs.style, style_);
    return is;
}

void hasDMA::View()
{
    baseDMA::View();
    std::cout << "Style: " << style << std::endl;
}
