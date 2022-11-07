// 6. Перепишите класс Stonewt (листинги 11.16 и 11.17) так, чтобы перегружались все шесть операций сравнения. 
// Операции должны сравнивать члены pounds и возвращать значение типа bool. 
// Напишите программу, которая объявляет массив из шести объектов Stonewt с инициализацией в объявлении первых трех из них. 
// Затем программа должна в цикле читать значения, используемые для установки остальных трех элементов массива. 
// После этого программа должна вывести самый маленький элемент, самый большой, а также количество элементов, которые больше или равны 11 стоунам. 
// (Простейший подход предполагает создание объекта Stonewt, инициализированного 11 стоунами, и сравнение с ним других объектов.)

// stonewt1.cpp -- реализация методов класса

#include <iostream>
#include "stonewt06.h"

using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds =  stn * Lbs_per_stn +lbs;
}

Stonewt::Stonewt()          // default constructor, wt = 0
{
    stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt()         // destructor
{
}

// show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

// conversion functions
Stonewt::operator int() const
{

    return int (pounds + 0.5);

}

Stonewt::operator double()const
{
    return pounds; 
}