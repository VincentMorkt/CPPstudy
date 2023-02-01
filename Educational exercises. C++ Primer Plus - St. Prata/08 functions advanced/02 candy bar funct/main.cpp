// 2. Структура CandyBar содержит три члена. Первый член хранит название коробки конфет. Второй - ее вес (который может иметь дробную часть),
// а третий - количество калорий (целое значение). Напишите программу, использующую функцию, которая принимает в качестве аргументов ссылку на CandyBar,
// указатель на char, значение double и значение int. Функция использует три последних значения для установки соответствующих членов структуры.
// Три последних аргумента должны иметь значения по умолчанию: "Millenn ium Munch", 2 . 85 и 350. Кроме того, программа должна использовать функцию,
// которая принимает в качестве аргумента ссылку на CandyBar и отображает содержимое этой структуры. Где необходимо, используйте const.

#include <iostream>
using namespace std;
struct CandyBar
{
    const char *name;
    double weight;
    int callories;
};
void show(const CandyBar &SR);
void fill(CandyBar &SR, const char *name = {"Millenn ium Munch"}, double weight = 2.85, int callories = 350); // функция записи

int main()
{

    CandyBar snack[4]; // объявление указателя на динамический массив структур (взял в 4.006)

    const char *ch = {"Mocha Munch"};
    fill(snack[0], ch, 2.3, 350);
    fill(snack[1], "Snickers", 1.7, 249);
    fill(snack[2], "Arrakis gummy worm", 7199980.02, 6420);
    fill(snack[3]);

    for (int i = 0; i < 4; i++)
        show(snack[i]);
    cin.get();
    return 0;
}

void show(const CandyBar &SR)
{
    cout << SR.name << endl
         << "weight: " << SR.weight << endl
         << "callories: " << SR.callories << endl
         << endl;
}
void fill(CandyBar &SR, const char *name, double weight, int callories)
{
    SR.name = name;
    SR.weight = weight;
    SR.callories = callories;
}