// 5. Перепишите класс Stonewt (листинги 11.16 и 11.17) так, чтобы он имел член состояния, который управляет тем, в какой форме интерпретируется объект: стоуны,
// целочисленное значение в фунтах или значение в фунтах с плавающей точкой. Перегрузите операцию << для замены методов show_stn() и show_lbs().
// Перегрузите операции сложения, вычитания и умножения значений Stonewt. Протестируйте полученный класс с помощью короткой программы,
// в которой используются все методы и друзья класса.

// stonewt05.h -- объявление класса Stonewt

#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

class stonewt
{
public:
    enum Mode // метки сосотояния
    {
        STN,
        PDS
    };

private:
    enum
    {
        Lbs_per_stn = 14 // фунтов на стоун
    };

    int stone;       // полных стоунов
    double pds_left; // дробное число фунтов
    double pounds;   // общий вес в фунтах
    Mode mode;       // член состояния
public:
    stonewt(double lbs, Mode form = PDS);          // конструктор для значения в фунтах
    stonewt(int stn, double lbs, Mode form = STN); // конструктор для значения в стоунах и фунтах
    stonewt();                                     // конструктор по умолчанию
    ~stonewt();

    void STN_mode() { mode = STN; } // смена состояния
    void PDS_mode() { mode = PDS; } // встроенные функции

    stonewt operator+(const stonewt &st) const; // перегруженные операции
    stonewt operator-(const stonewt &st) const;
    stonewt operator*(double n) const;

    friend stonewt operator*(double n, const stonewt &st) { return st * n; } // дружественные функции

    friend std::ostream &operator<<(std::ostream &os, const stonewt &st);
    // void show_lbs() const; // отображение в формате фунтов
    // void show_stn() const; // отображение в формате стоунов
};
#endif