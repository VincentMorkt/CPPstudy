// stonewt.cpp -- определение методов класса Stonewt

#include <iostream>
#include "stonewt.h"

using std::cout;

stonewt::stonewt(double lbs) // конструктор для значения в фунтах
{
    stone = int(lbs) / Lbs_per_stn; // целочисленное деление
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

stonewt::stonewt(int stn, double lbs) // конструктор для значения в стоунах и фунтах
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

stonewt::stonewt() // конструктор по умолчанию
{
    stone = pounds = pds_left = 0;
}

stonewt::~stonewt() {} // деструктор

void stonewt::show_lbs() const // отображение в формате фунтов
{
    cout << pounds << " pounds\n";
}

void stonewt::show_stn() const // отображение в формате стоунов
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}