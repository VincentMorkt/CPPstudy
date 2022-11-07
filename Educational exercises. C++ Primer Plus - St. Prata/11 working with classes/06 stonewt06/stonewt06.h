// 6. Перепишите класс Stonewt (листинги 11.16 и 11.17) так, чтобы перегружались все шесть операций сравнения.
// Операции должны сравнивать члены pounds и возвращать значение типа bool.
// Напишите программу, которая объявляет массив из шести объектов Stonewt с инициализацией в объявлении первых трех из них.
// Затем программа должна в цикле читать значения, используемые для установки остальных трех элементов массива.
// После этого программа должна вывести самый маленький элемент, самый большой, а также количество элементов, которые больше или равны 11 стоунам.
// (Простейший подход предполагает создание объекта Stonewt, инициализированного 11 стоунами, и сравнение с ним других объектов.)

// stonewt06.h -- объявление класса

#ifndef STONEWT1_H_
#define STONEWT1_H_
class Stonewt
{
private:
    enum
    {
        Lbs_per_stn = 14
    };               // pounds per stone
    int stone;       // whole stones
    double pds_left; // fractional pounds
    double pounds;   // entire weight in pounds
public:
    Stonewt(double lbs);          // construct from double pounds
    Stonewt(int stn, double lbs); // construct from stone, lbs
    Stonewt();                    // default constructor
    ~Stonewt();
    void show_lbs() const; // show weight in pounds format
    void show_stn() const; // show weight in stone format

    // перегруженные операции сравнения
    bool operator==(const Stonewt &st) const { return (stone == st.stone) ? true : false; };
    bool operator!=(const Stonewt &st) const { return (stone != st.stone) ? true : false; };
    bool operator>=(const Stonewt &st) const { return (stone >= st.stone) ? true : false; };
    bool operator<=(const Stonewt &st) const { return (stone <= st.stone) ? true : false; };
    bool operator>(const Stonewt &st) const { return (stone > st.stone) ? true : false; };
    bool operator<(const Stonewt &st) const { return (stone < st.stone) ? true : false; };

    // conversion functions
    operator int() const;
    operator double() const;
};
#endif