// stonewt.h -- объявление класса Stonewt

#ifndef STONEWT_H_
#define STONEWT_H_

class stonewt
{
private:
    enum
    {
        Lbs_per_stn = 14 // фунтов на стоун
    };
    int stone;       // полных стоунов
    double pds_left; // дробное число фунтов
    double pounds;   // общий вес в фунтах
public:
    stonewt(double lbs);          // конструктор для значения в фунтах
    stonewt(int stn, double lbs); // конструктор для значения в стоунах и фунтах
    stonewt();                    // конструктор по умолчанию
    ~stonewt();
    void show_lbs() const; // отображение в формате фунтов
    void show_stn() const; // отображение в формате стоунов
    
};
#endif