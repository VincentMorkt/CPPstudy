/*Структура CandyBar содержит три члена. Первый из них хранит название коробки конфет. Второй - ее вес (который может иметь дробную часть), а третий - число калорий (целое значение).
Напишите программу, объявляющую эту структуру и создающую переменную типа CandyBar по имени snack, инициализируя ее члены значениями "Mocha Munch ", 2.3 и 350, соответственно.
Инициализация должна быть частью объявления snack. И, наконец, программа должна отобразить содержимое этой переменной.*/

#include <iostream>
#include <string>
using namespace std;
struct CandyBar // объявление структуры
{
    string titel; // члены структуры
    float weight;
    int calories;
};
int main()
{
    CandyBar snack{"Mocha Munch", 2.3, 350};  // объявление объекта структуры и инициализация его членов
    cout << "Titel:\t" << snack.titel << endl // вывод членов структуры
         << "Weight:\t" << snack.weight << endl
         << "Calories: " << snack.calories << endl;
    cin.get();
    return 0;
}